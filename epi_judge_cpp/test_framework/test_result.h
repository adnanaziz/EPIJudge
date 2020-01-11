
#pragma once

namespace test_framework {
// We may not detect STACK_OVERFLOW in C++ (Java and Python detect that).
enum class TestResult {
  PASSED = 0,
  FAILED = 1,
  TIMEOUT = 2,
  UNKNOWN_EXCEPTION = 3,
  /*STACK_OVERFLOW*/
  RUNTIME_ERROR = 5,
};
}  // namespace test_framework
