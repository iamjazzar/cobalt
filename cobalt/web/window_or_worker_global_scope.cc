// Copyright 2022 The Cobalt Authors. All Rights Reserved.
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

#include "cobalt/web/window_or_worker_global_scope.h"

#include "cobalt/script/environment_settings.h"
#include "cobalt/web/event_target.h"

namespace cobalt {
namespace dom {
class Window;
}  // namespace dom
namespace worker {
class DedicatedWorkerGlobalScope;
class ServiceWorkerGlobalScope;
}  // namespace worker
namespace web {
WindowOrWorkerGlobalScope::WindowOrWorkerGlobalScope(
    script::EnvironmentSettings* settings, StatTracker* stat_tracker,
    base::ApplicationState initial_state)
    // Global scope object EventTargets require special handling for onerror
    // events, see EventTarget constructor for more details.
    : EventTarget(settings, kUnpackOnErrorEvents),
      crypto_(new Crypto()),
      window_timers_(this, stat_tracker, debugger_hooks(), initial_state) {}

bool WindowOrWorkerGlobalScope::IsWindow() {
  return GetWrappableType() == base::GetTypeId<dom::Window>();
}

bool WindowOrWorkerGlobalScope::IsDedicatedWorker() {
  return GetWrappableType() ==
         base::GetTypeId<worker::DedicatedWorkerGlobalScope>();
}

bool WindowOrWorkerGlobalScope::IsServiceWorker() {
  return GetWrappableType() ==
         base::GetTypeId<worker::ServiceWorkerGlobalScope>();
}

int WindowOrWorkerGlobalScope::SetTimeout(
    const web::WindowTimers::TimerCallbackArg& handler, int timeout) {
  return window_timers_.SetTimeout(handler, timeout);
}

void WindowOrWorkerGlobalScope::ClearTimeout(int handle) {
  window_timers_.ClearTimeout(handle);
}

int WindowOrWorkerGlobalScope::SetInterval(
    const web::WindowTimers::TimerCallbackArg& handler, int timeout) {
  return window_timers_.SetInterval(handler, timeout);
}

void WindowOrWorkerGlobalScope::ClearInterval(int handle) {
  window_timers_.ClearInterval(handle);
}

void WindowOrWorkerGlobalScope::DestroyTimers() {
  window_timers_.DisableCallbacks();
}

scoped_refptr<Crypto> WindowOrWorkerGlobalScope::crypto() const {
  return crypto_;
}

}  // namespace web
}  // namespace cobalt
