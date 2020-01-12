
#pragma once

#include <chrono>

#include "test_timer.h"

namespace test_framework {

class TimeoutException {
 public:
  explicit TimeoutException(const std::chrono::seconds& timeout_seconds)
      : timer_(timeout_seconds) {}

  const TestTimer& GetTimer() const { return timer_; }

 private:
  TestTimer timer_;
};
}  // namespace test_framework
