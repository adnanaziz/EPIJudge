
#pragma once

#include <algorithm>
#include <chrono>
#include <numeric>
#include <string>
#include <vector>

namespace test_framework {
namespace test_timer {
std::string LeftPaddingString(const std::string& str, int format_width) {
  return std::string(std::max(static_cast<int>(format_width - str.size()), 0),
                     ' ')
      .append(str);
}
}  // namespace test_timer

class TestTimer {
 public:
  TestTimer() = default;

  explicit TestTimer(const std::chrono::seconds& duration_seconds) {
    duration_us_ = std::chrono::duration_cast<std::chrono::microseconds>(
        duration_seconds);
  }

  void Start() { start_ = clock_t::now(); }

  void Stop() {
    duration_us_ += std::chrono::duration_cast<std::chrono::microseconds>(
        clock_t::now() - start_);
  }

  std::chrono::microseconds GetMicroseconds() const { return duration_us_; }

 private:
  using clock_t = std::chrono::high_resolution_clock;

  clock_t::time_point start_;
  std::chrono::microseconds duration_us_{0};
};

std::string DurationToString(const std::chrono::microseconds& dur) {
  constexpr int MILLI_TO_MICRO = 1000;
  constexpr int SECOND_TO_MICRO = MILLI_TO_MICRO * 1000;
  constexpr int DURATION_FORMAT_WIDTH = 4;

  if (dur == dur.zero()) {
    return "  <1 us";
  } else if (dur.count() < MILLI_TO_MICRO) {
    return test_timer::LeftPaddingString(std::to_string(dur.count()),
                                         DURATION_FORMAT_WIDTH) +
           " us";
  } else if (dur.count() < SECOND_TO_MICRO) {
    return test_timer::LeftPaddingString(
               std::to_string(
                   std::chrono::duration_cast<std::chrono::milliseconds>(dur)
                       .count()),
               DURATION_FORMAT_WIDTH) +
           " ms";
  } else {
    return test_timer::LeftPaddingString(
               std::to_string(
                   std::chrono::duration_cast<std::chrono::seconds>(dur)
                       .count()),
               DURATION_FORMAT_WIDTH) +
           "  s";
  }
}

std::pair<std::chrono::microseconds, std::chrono::microseconds>
AvgAndMedianFromDurations(std::vector<std::chrono::microseconds> durations) {
  std::sort(std::begin(durations), std::end(durations));
  auto avg = std::accumulate(std::begin(durations), std::end(durations),
                             std::chrono::microseconds::zero()) /
             durations.size();
  auto median = durations.size() & 1 ? durations[durations.size() / 2]
                                     : (durations[durations.size() / 2 - 1] +
                                        durations[durations.size() / 2]) /
                                           2;
  return {avg, median};
}
}  // namespace test_framework
