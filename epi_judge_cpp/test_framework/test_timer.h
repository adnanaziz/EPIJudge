// @library
#pragma once

#include <algorithm>
#include <chrono>
#include <string>

class TestTimer {
 public:
  void Start() { start_ = clock_t::now(); }

  void Stop() {
    if (!Stopped()) {
      stop_ = clock_t::now();
    }
  }

  bool Started() const { return start_.time_since_epoch().count(); }

  bool Stopped() const { return stop_.time_since_epoch().count(); }

  std::chrono::microseconds GetMicroseconds() const {
    return std::chrono::duration_cast<std::chrono::microseconds>(stop_ -
                                                                 start_);
  }

  bool HasValidResult() const { return Started() && Stopped(); }

 private:
  using clock_t = std::chrono::high_resolution_clock;

  clock_t::time_point start_;
  clock_t::time_point stop_;
};

std::string LeftPaddingString(const std::string& str, int format_width) {
  return std::string(std::max(static_cast<int>(format_width - str.size()), 0),
                     ' ')
      .append(str);
}

std::string DurationToString(const std::chrono::microseconds& dur) {
  constexpr int kFormatWidth = 4;
  constexpr int MICRO_TO_MILLI = std::chrono::microseconds::period::den /
                                 std::chrono::milliseconds::period::den;
  constexpr int MICRO_TO_SECOND = std::chrono::microseconds::period::den;
  if (dur == dur.zero()) {
    return "  <1 us";
  } else if (dur.count() < MICRO_TO_MILLI) {
    return LeftPaddingString(std::to_string(dur.count()), kFormatWidth) +
           " us";
  } else if (dur.count() < MICRO_TO_SECOND) {
    return LeftPaddingString(std::to_string(dur.count() / MICRO_TO_MILLI),
                             kFormatWidth) +
           " ms";
  } else {
    return LeftPaddingString(std::to_string(dur.count() / MICRO_TO_SECOND),
                             kFormatWidth) +
           "  s";
  }
}
