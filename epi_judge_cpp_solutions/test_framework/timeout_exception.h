
#pragma once

#include <chrono>

#include "test_timer.h"

class TimeoutException {
 public:
  explicit TimeoutException(const std::chrono::milliseconds& ms)
      : timer_(ms) {}
  const TestTimer& GetTimer() const { return timer_; }

 private:
  TestTimer timer_;
};
