// @library
#pragma once

#include <chrono>
#include <future>

#include "test_timer.h"
#include "test_utils_meta.h"
#include "timeout_exception.h"

class TimedExecutor {
 public:
  explicit TimedExecutor(const std::chrono::seconds& timeout_seconds)
      : timeout_seconds_(timeout_seconds) {}

  /**
   * Invokes func with a specified timeout_seconds.
   * If func takes more than timeout_seconds seconds to run,
   * TimeoutException is thrown.
   * If timeout_seconds == 0, it simply calls the function.
   *
   * @return whatever func returns
   */
  template <typename Func>
  decltype(auto) Run(Func func) {
    if (timeout_seconds_ == timeout_seconds_.zero()) {
      // timeout is disabled
      timer_.Start();
      OnScopeExit timer_stopper(std::bind(&TestTimer::Stop, &timer_));

      return func();
    } else {
      auto future = std::async(std::launch::async, [&] {
        timer_.Start();
        OnScopeExit timer_stopper(std::bind(&TestTimer::Stop, &timer_));
        return func();
      });

      if (future.wait_for(timeout_seconds_) == std::future_status::ready) {
        return future.get();
      } else {
        throw TimeoutException(timeout_seconds_);
      }
    }
  }

  const TestTimer& GetTimer() const { return timer_; }

 private:
  TestTimer timer_;
  std::chrono::seconds timeout_seconds_;
};

template <typename Func, typename... ArgsFwd>
decltype(auto) InvokeWithExecutor(HasNoExecutorHookTag, Func& f,
                                  TimedExecutor& executor,
                                  ArgsFwd&&... args) {
  return executor.Run([&] { return f(std::forward<ArgsFwd>(args)...); });
}

template <typename Func, typename... ArgsFwd>
decltype(auto) InvokeWithExecutor(HasExecutorHookTag, Func& f,
                                  TimedExecutor& executor,
                                  ArgsFwd&&... args) {
  return f(executor, std::forward<ArgsFwd>(args)...);
}
