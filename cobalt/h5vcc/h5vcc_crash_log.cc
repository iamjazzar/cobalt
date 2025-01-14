// Copyright 2017 The Cobalt Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "cobalt/h5vcc/h5vcc_crash_log.h"

#include <map>
#include <string>

#include "base/atomicops.h"
#include "base/memory/singleton.h"
#include "base/synchronization/lock.h"

#if SB_HAS(CORE_DUMP_HANDLER_SUPPORT)
#include STARBOARD_CORE_DUMP_HANDLER_INCLUDE
#endif  // SB_HAS(CORE_DUMP_HANDLER_SUPPORT)

#include "starboard/system.h"

namespace cobalt {
namespace h5vcc {

// We keep a global mapping of all registered logs.  When a crash occurs, we
// will iterate through the mapping in this dictionary to extract all
// logged entries and write them to the system's crash logger via Starboard.
class CrashLogDictionary {
 public:
  static CrashLogDictionary* GetInstance() {
    return base::Singleton<CrashLogDictionary, base::DefaultSingletonTraits<
                                                   CrashLogDictionary> >::get();
  }

  void SetString(const std::string& key, const std::string& value) {
    base::AutoLock lock(mutex_);
    // While the lock prevents contention between other calls to SetString(),
    // the atomics guard against OnCrash(), which doesn't acquire |mutex_|, from
    // accessing the data at the same time.  In the case that OnCrash() is
    // being called, we give up and skip adding the data.
    if (base::subtle::Acquire_CompareAndSwap(&accessing_log_data_, 0, 1) == 0) {
      string_log_map_[key] = value;
      base::subtle::Release_Store(&accessing_log_data_, 0);
    }
  }

 private:
  CrashLogDictionary() : accessing_log_data_(0) {
#if SB_HAS(CORE_DUMP_HANDLER_SUPPORT)
    SbCoreDumpRegisterHandler(&CoreDumpHandler, this);
#endif
  }

  static void CoreDumpHandler(void* context) {
    CrashLogDictionary* crash_log_dictionary =
        static_cast<CrashLogDictionary*>(context);
    crash_log_dictionary->OnCrash();
  }

  void OnCrash() {
#if SB_HAS(CORE_DUMP_HANDLER_SUPPORT)
    // Check that we're not already updating log data.  If we are, we just
    // give up and skip recording any crash data, but hopefully this is rare.
    if (base::subtle::Acquire_CompareAndSwap(&accessing_log_data_, 0, 1) == 0) {
      for (StringMap::const_iterator iter = string_log_map_.begin();
           iter != string_log_map_.end(); ++iter) {
        SbCoreDumpLogString(iter->first.c_str(), iter->second.c_str());
      }
      base::subtle::Release_Store(&accessing_log_data_, 0);
    }
#endif
  }

  friend struct base::DefaultSingletonTraits<CrashLogDictionary>;

  base::subtle::Atomic32 accessing_log_data_;

  // It is possible for multiple threads to call the H5VCC interface at the
  // same time, and they will all forward to this global singleton, so we
  // use this mutex to protect against concurrent access.
  base::Lock mutex_;

  typedef std::map<std::string, std::string> StringMap;
  // Keeps track of all string values to be logged when a crash occurs.
  StringMap string_log_map_;

  DISALLOW_COPY_AND_ASSIGN(CrashLogDictionary);
};

bool H5vccCrashLog::SetString(const std::string& key,
                              const std::string& value) {
  // Forward the call to a global singleton so that we keep a consistent crash
  // log globally.
  CrashLogDictionary::GetInstance()->SetString(key, value);

  return true;
}

void H5vccCrashLog::TriggerCrash(H5vccCrashType intent) {
  if (intent == kH5vccCrashTypeNullDereference) {
    *(reinterpret_cast<volatile char*>(0)) = 0;
  }
  if (intent == kH5vccCrashTypeIllegalInstruction) {
#if SB_IS(ARCH_ARM) || SB_IS(ARCH_ARM64)
    __asm(".word 0xf7f0a000\n");
#elif !SB_IS(ARCH_X64)  // inline asm not allowed on 64bit MSVC
    __asm("ud2");
#endif
  }
  if (intent == kH5vccCrashTypeDebugger) {
    SbSystemBreakIntoDebugger();
  }
  if (intent == kH5vccCrashTypeOutOfMemory) {
    SbMemoryAllocateAligned(128, SIZE_MAX);
  }
}

bool H5vccCrashLog::Register(const std::string& name,
                             const std::string& description,
                             WatchdogState watchdog_state,
                             int64_t time_interval, int64_t time_wait,
                             WatchdogReplace watchdog_replace) {
  watchdog::Watchdog* watchdog = watchdog::Watchdog::GetInstance();
  if (watchdog) {
    base::ApplicationState monitor_state;
    switch (watchdog_state) {
      case kWatchdogStateStarted:
        monitor_state = base::kApplicationStateStarted;
        break;
      case kWatchdogStateBlurred:
        monitor_state = base::kApplicationStateBlurred;
        break;
      case kWatchdogStateConcealed:
        monitor_state = base::kApplicationStateConcealed;
        break;
      case kWatchdogStateFrozen:
        monitor_state = base::kApplicationStateFrozen;
        break;
      default:
        monitor_state = base::kApplicationStateStarted;
    }
    watchdog::Replace replace;
    switch (watchdog_replace) {
      case kWatchdogReplaceNone:
        replace = watchdog::NONE;
        break;
      case kWatchdogReplacePing:
        replace = watchdog::PING;
        break;
      case kWatchdogReplaceAll:
        replace = watchdog::ALL;
        break;
      default:
        replace = watchdog::NONE;
    }
    return watchdog->Register(name, description, monitor_state, time_interval,
                              time_wait, replace);
  }
  return false;
}

bool H5vccCrashLog::Unregister(const std::string& name) {
  watchdog::Watchdog* watchdog = watchdog::Watchdog::GetInstance();
  if (watchdog) return watchdog->Unregister(name);
  return false;
}

bool H5vccCrashLog::Ping(const std::string& name,
                         const std::string& ping_info) {
  watchdog::Watchdog* watchdog = watchdog::Watchdog::GetInstance();
  if (watchdog) return watchdog->Ping(name, ping_info);
  return false;
}

std::string H5vccCrashLog::GetWatchdogViolations(bool current) {
  watchdog::Watchdog* watchdog = watchdog::Watchdog::GetInstance();
  if (watchdog) return watchdog->GetWatchdogViolations(current);
  return "";
}

bool H5vccCrashLog::GetPersistentSettingWatchdogCrash() {
  watchdog::Watchdog* watchdog = watchdog::Watchdog::GetInstance();
  if (watchdog) return watchdog->GetPersistentSettingWatchdogCrash();
  return false;
}

void H5vccCrashLog::SetPersistentSettingWatchdogCrash(bool can_trigger_crash) {
  watchdog::Watchdog* watchdog = watchdog::Watchdog::GetInstance();
  if (watchdog) watchdog->SetPersistentSettingWatchdogCrash(can_trigger_crash);
}

}  // namespace h5vcc
}  // namespace cobalt
