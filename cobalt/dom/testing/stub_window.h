// Copyright 2016 The Cobalt Authors. All Rights Reserved.
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

#ifndef COBALT_DOM_TESTING_STUB_WINDOW_H_
#define COBALT_DOM_TESTING_STUB_WINDOW_H_

#include <memory>
#include <string>
#include <utility>

#include "base/bind.h"
#include "base/callback.h"
#include "base/optional.h"
#include "cobalt/base/debugger_hooks.h"
#include "cobalt/css_parser/parser.h"
#include "cobalt/cssom/viewport_size.h"
#include "cobalt/dom/captions/system_caption_settings.h"
#include "cobalt/dom/dom_settings.h"
#include "cobalt/dom/local_storage_database.h"
#include "cobalt/dom/testing/stub_environment_settings.h"
#include "cobalt/dom/window.h"
#include "cobalt/dom_parser/parser.h"
#include "cobalt/loader/fetcher_factory.h"
#include "cobalt/loader/loader_factory.h"
#include "cobalt/script/global_environment.h"
#include "cobalt/script/javascript_engine.h"
#include "cobalt/web/context.h"
#include "cobalt/web/environment_settings.h"
#include "cobalt/web/testing/stub_web_context.h"
#include "starboard/window.h"
#include "url/gurl.h"

namespace cobalt {
namespace dom {
class OnScreenKeyboardBridge;
namespace testing {
// A helper class for tests that brings up a dom::Window with a number of parts
// stubbed out.
class StubWindow {
 public:
  explicit StubWindow(
      const DOMSettings::Options& options = DOMSettings::Options(),
      OnScreenKeyboardBridge* on_screen_keyboard_bridge = nullptr,
      web::testing::StubWebContext* stub_web_context =
          new web::testing::StubWebContext())
      : css_parser_(css_parser::Parser::Create()),
        dom_parser_(
            new dom_parser::Parser(base::Bind(&StubLoadCompleteCallback))),
        local_storage_database_(NULL),
        dom_stat_tracker_(new dom::DomStatTracker("StubWindow")) {
    web_context_.reset(stub_web_context);
    web_context_->setup_environment_settings(
        new dom::testing::StubEnvironmentSettings(options));
    web_context_->environment_settings()->set_base_url(GURL("about:blank"));
    web_context_->set_fetcher_factory(new loader::FetcherFactory(NULL));
    loader_factory_.reset(new loader::LoaderFactory(
        "Test", web_context_->fetcher_factory(), NULL,
        web_context_->environment_settings()->debugger_hooks(), 0,
        base::ThreadPriority::DEFAULT));
    system_caption_settings_ = new cobalt::dom::captions::SystemCaptionSettings(
        web_context_->environment_settings());

    window_ = new dom::Window(
        web_context_->environment_settings(), cssom::ViewportSize(1920, 1080),
        base::kApplicationStateStarted, css_parser_.get(), dom_parser_.get(),
        web_context_->fetcher_factory(), loader_factory_.get(), nullptr,
        nullptr, nullptr, nullptr, nullptr, nullptr, &local_storage_database_,
        nullptr, nullptr, nullptr, nullptr,
        global_environment()->script_value_factory(), nullptr,
        dom_stat_tracker_.get(), "en", base::Callback<void(const GURL&)>(),
        base::Bind(&StubLoadCompleteCallback), nullptr,
        network_bridge::PostSender(), csp::kCSPRequired,
        web::kCspEnforcementEnable, base::Closure() /* csp_policy_changed */,
        base::Closure() /* ran_animation_frame_callbacks */,
        dom::Window::CloseCallback() /* window_close */,
        base::Closure() /* window_minimize */, on_screen_keyboard_bridge,
        nullptr /* camera_3d */, dom::Window::OnStartDispatchEventCallback(),
        dom::Window::OnStopDispatchEventCallback(),
        dom::ScreenshotManager::ProvideScreenshotFunctionCallback(),
        nullptr /* synchronous_loader_interrupt */,
        false /* enable_inline_script_warnings */, nullptr /* ui_nav_root */,
        true /* enable_map_to_mesh */, 0 /* csp_insecure_allowed_token */,
        0 /* dom_max_element_depth */, 1.f /* video_playback_rate_multiplier */,
        dom::Window::kClockTypeSystemTime /* clock_type */,
        dom::Window::CacheCallback() /* splash_screen_cache_callback */,
        system_caption_settings_ /* captions */
        );
    base::polymorphic_downcast<dom::DOMSettings*>(
        web_context_->environment_settings())
        ->set_window(window_);
    global_environment()->CreateGlobalObject(
        window_, web_context_->environment_settings());
  }
  virtual ~StubWindow() { window_->DestroyTimers(); }

  web::testing::StubWebContext* web_context() { return web_context_.get(); }
  scoped_refptr<dom::Window> window() { return window_; }
  scoped_refptr<script::GlobalEnvironment> global_environment() {
    return web_context_->global_environment();
  }
  css_parser::Parser* css_parser() { return css_parser_.get(); }
  web::EnvironmentSettings* environment_settings() {
    return web_context_->environment_settings();
  }

 private:
  static void StubLoadCompleteCallback(
      const base::Optional<std::string>& error) {}

  std::unique_ptr<css_parser::Parser> css_parser_;
  std::unique_ptr<dom_parser::Parser> dom_parser_;
  std::unique_ptr<loader::LoaderFactory> loader_factory_;
  dom::LocalStorageDatabase local_storage_database_;
  std::unique_ptr<dom::DomStatTracker> dom_stat_tracker_;
  std::unique_ptr<web::testing::StubWebContext> web_context_;
  scoped_refptr<dom::Window> window_;

  scoped_refptr<cobalt::dom::captions::SystemCaptionSettings>
      system_caption_settings_;
};

}  // namespace testing
}  // namespace dom
}  // namespace cobalt

#endif  // COBALT_DOM_TESTING_STUB_WINDOW_H_
