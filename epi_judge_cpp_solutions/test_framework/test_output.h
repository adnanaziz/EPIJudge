
#pragma once

#include "test_timer.h"

namespace test_framework {
struct TestOutput {
  TestTimer timer;
  std::vector<int> metrics;
};
}  // namespace test_framework
