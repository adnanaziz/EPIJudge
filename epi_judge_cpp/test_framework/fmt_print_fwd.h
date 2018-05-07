
#pragma once

#include <iosfwd>

template <typename T>
std::ostream& PrintTo(std::ostream& out, const T& x);

template <typename... Args>
std::string FmtStr(const std::string& fmt, const Args&... args);
