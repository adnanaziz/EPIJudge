
#pragma once

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

#include "console_color.h"
#include "test_failure.h"
#include "test_result.h"
#include "test_timer.h"

struct EscapeNewline {
  const std::string& str;

  friend std::ostream& operator<<(std::ostream& out,
                                  const EscapeNewline& it) {
    for (auto& c : it.str) {
      switch (c) {
        case '\n':
          out << "\\n";
          break;
        case '\r':
          out << "\\r";
          break;
        default:
          out << c;
      }
    }
    return out;
  }
};

void ClearLineIfTty() {
  if (platform::UseTtyOutput()) {
    platform::StdOutClearLine();
  } else {
    std::cout << '\n';
  };
}

void PrintTestResult(const TestResult& test_result) {
  switch (test_result) {
    case PASSED:
      PrintStdOutColored(console_color::ConsoleColor::FG_GREEN, "PASSED");
      break;
    case FAILED:
      PrintStdOutColored(console_color::ConsoleColor::FG_RED, "FAILED");
      break;
    case TIMEOUT:
      PrintStdOutColored(console_color::ConsoleColor::FG_BLUE, "TIMEOUT");
      break;
    case UNKNOWN_EXCEPTION:
      PrintStdOutColored(console_color::ConsoleColor::FG_RED, "UNHANDLED EXCEPTION");
      break;
    default:
      throw std::runtime_error("Unknown TestResult");
  }
}

void PrintTestInfo(const TestResult& test_result, int test_nr,
                   int total_tests, const std::string& diagnostic,
                   const TestTimer& timer) {
  static bool caret_at_line_start = true;

  if (!caret_at_line_start) {
    ClearLineIfTty();
  }

  auto total_tests_str = std::to_string(total_tests);
  std::cout << "Test ";
  PrintTestResult(test_result);
  std::cout << " (" << std::setw(static_cast<int>(total_tests_str.size()))
            << test_nr << '/' << total_tests_str << ")";

  if (timer.HasValidResult()) {
    std::cout << " [" << DurationToString(timer.GetMicroseconds()) << "]";
  }

  caret_at_line_start = false;

  if (test_result != TestResult::PASSED) {
    std::cout << ' ' << diagnostic << '\n';
    caret_at_line_start = true;
  }
}

std::string GenSpaces(size_t count) { return std::string(count, ' '); }

void PrintFailedTest(const std::vector<std::string>& param_names,
                     const std::vector<std::string>& arguments,
                     TestFailure& test_failure) {
  size_t max_col_size = test_failure.GetMaxPropertyNameLength();

  for (auto& param : param_names) {
    if (param.size() > max_col_size) {
      max_col_size = param.size();
    }
  }

  PrintStdOutColored(console_color::ConsoleColor::FG_YELLOW, "Arguments");
  std::cout << std::endl;

  for (unsigned int i = 0; i < arguments.size(); ++i) {
    std::cout << '\t';
    PrintStdOutColored(console_color::ConsoleColor::FG_YELLOW, param_names[i]);
    std::cout << ": " << GenSpaces(max_col_size - param_names[i].size())
              << EscapeNewline{arguments[i]} << std::endl;
  }

  auto properties = test_failure.GetProperties();
  PrintStdOutColored(console_color::ConsoleColor::FG_YELLOW, "\nFailure info\n");

  for (auto& prop : properties) {
    std::cout << '\t';
    PrintStdOutColored(console_color::ConsoleColor::FG_YELLOW, prop.Name());
    std::cout << ": " << GenSpaces(max_col_size - prop.Name().size())
              << prop.Value() << std::endl;
  }
}

void PrintPostRunStats(
    int tests_passed, int total_tests, const std::string& complexity,
    const std::vector<std::chrono::microseconds>& durations) {
  if (!durations.empty()) {
    if (!complexity.empty()) {
      std::cout << "Time complexity:      " << complexity << std::endl;
    }

    auto avg_median = AvgAndMedianFromDurations(durations);
    std::cout << "Average running time: "
              << DurationToString(avg_median.first) << std::endl
              << "Median running time:  "
              << DurationToString(avg_median.second) << std::endl;
  }

  if (tests_passed < total_tests) {
    std::cout << "*** You've passed " << tests_passed << "/" << total_tests
              << " tests. ***" << std::endl;
  } else {
    std::cout << "*** You've passed ALL tests. Congratulations! ***"
              << std::endl;
  }
}
