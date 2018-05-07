
#pragma once

#include <algorithm>
#include <chrono>
#include <numeric>
#include <string>
#include <vector>

class TestTimer {
 public:
  TestTimer() = default;

  explicit TestTimer(const std::chrono::milliseconds& duration_ms) {
    stop_ = clock_t::now();
    start_ = stop_ - duration_ms;
  }

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
  constexpr int MICRO_TO_MILLI = 1000;
  constexpr int MICRO_TO_SECOND = MICRO_TO_MILLI * 1000;
  constexpr int FORMAT_WIDTH = 4;

  if (dur == dur.zero()) {
    return "  <1 us";
  } else if (dur.count() < MICRO_TO_MILLI) {
    return LeftPaddingString(std::to_string(dur.count()), FORMAT_WIDTH) +
           " us";
  } else if (dur.count() < MICRO_TO_SECOND) {
    return LeftPaddingString(std::to_string(dur.count() / MICRO_TO_MILLI),
                             FORMAT_WIDTH) +
           " ms";
  } else {
    return LeftPaddingString(std::to_string(dur.count() / MICRO_TO_SECOND),
                             FORMAT_WIDTH) +
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
