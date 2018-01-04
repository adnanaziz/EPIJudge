// @library
#pragma once

#include <ostream>
#include "platform.h"

enum TestResult { PASSED, FAILED, TIMEOUT, UNKNOWN_EXCEPTION };

namespace console_color {
const char* FG_RED = "\033[31m";
const char* FG_GREEN = "\033[32m";
const char* FG_BLUE = "\033[34m";
const char* FG_DEFAULT = "\033[39m";
};  // namespace console_color

bool UseTtyOutput() {
  static int cached = os::IsATty(os::StdOutFd());
  return static_cast<bool>(cached);
}

inline bool PlatformSupportsColor() {
#ifdef _WINDOWS
  return false;  // Windows doesn't support coloring through escape codes
#else
  return true;
#endif
}

std::string Colored(std::string text, const char* color) {
  if (UseTtyOutput() && PlatformSupportsColor()) {
    return color + std::move(text) + console_color::FG_DEFAULT;
  } else {
    return std::move(text);
  }
}

std::ostream& operator<<(std::ostream& out, const TestResult& tr) {
  switch (tr) {
    case PASSED:
      return out << Colored("PASSED", console_color::FG_GREEN);
    case FAILED:
      return out << Colored("FAILED", console_color::FG_RED);
    case TIMEOUT:
      return out << Colored("TIMEOUT", console_color::FG_BLUE);
    case UNKNOWN_EXCEPTION:
      return out << Colored("UNHANDLED EXCEPTION", console_color::FG_RED);
    default:
      throw std::runtime_error("Unknown TestResult");
  }
}
