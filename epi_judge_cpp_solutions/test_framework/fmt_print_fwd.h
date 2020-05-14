
#pragma once

#include <iosfwd>

namespace test_framework {
template <typename T>
std::ostream& PrintTo(std::ostream& out, const T& x);

template <typename... Args>
std::string FmtStr(const std::string& fmt, const Args&... args);
}  // namespace test_framework
