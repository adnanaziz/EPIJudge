// @library
#pragma once

#include <iomanip>
#include <iostream>
#include <string>

#include "console_color.h"
#include "fmt_print.h"
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

void ReturnCaretIfTtyOutput(std::ostream& os) {
  if (platform::UseTtyOutput()) {
    os << '\r';
  } else {
    os << '\n';
  };
}

void PrintTestResult(const TestResult& test_result) {
  switch (test_result) {
    case PASSED:
      PrintStdOutColored(ConsoleColor::FG_GREEN, "PASSED");
      break;
    case FAILED:
      PrintStdOutColored(ConsoleColor::FG_RED, "FAILED");
      break;
    case TIMEOUT:
      PrintStdOutColored(ConsoleColor::FG_BLUE, "TIMEOUT");
      break;
    case UNKNOWN_EXCEPTION:
      PrintStdOutColored(ConsoleColor::FG_RED, "UNHANDLED EXCEPTION");
      break;
    default:
      throw std::runtime_error("Unknown TestResult");
  }
}

void PrintTestInfo(const TestResult& test_result, int test_nr,
                   int total_tests, const std::string& diagnostic,
                   const TestTimer& timer) {
  ReturnCaretIfTtyOutput(std::cout);

  auto total_tests_str = std::to_string(total_tests);
  std::cout << "Test ";
  PrintTestResult(test_result);
  std::cout << " (" << std::setw(static_cast<int>(total_tests_str.size()))
            << test_nr << '/' << total_tests_str << ")";

  if (timer.HasValidResult()) {
    std::cout << " [" << DurationToString(timer.GetMicroseconds()) << "]";
  }

  if (test_result != TestResult::PASSED) {
    std::cout << ' ' << diagnostic << '\n';
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

  for (unsigned int i = 0; i < arguments.size(); ++i) {
    std::cout << '\t' << param_names[i] << ": "
              << GenSpaces(max_col_size - param_names[i].size())
              << EscapeNewline{arguments[i]} << std::endl;
  }

  auto properties = test_failure.GetProperties();

  for (auto& prop : properties) {
    std::cout << FmtStr("\t{}: {}{}\n", prop.Name(),
                        GenSpaces(max_col_size - prop.Name().size()),
                        prop.Value());
  }
}

void PrintPostRunStats(int tests_passed, int total_tests,
                       std::vector<std::chrono::microseconds>& durations) {
  if (!durations.empty()) {
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
