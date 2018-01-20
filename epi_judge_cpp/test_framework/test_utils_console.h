// @library
#pragma once

#include <iomanip>
#include <iostream>
#include <string>

#include "console_color.h"
#include "test_result.h"
#include "test_timer.h"
#include "test_utils_serialization_traits.h"

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

std::string GenSpaces(size_t count) {
  return std::string(count, ' ');
}

template <typename TestOutputT>
void PrintFailedTest(const std::vector<std::string>& arg_names,
                     const std::vector<std::string>& arguments,
                     const TestOutputT& test_output,
                     const std::string& test_explanation) {
  static const std::string expected_str = "expected";
  static const std::string result_str = "result";
  static const std::string explanation_str = "explanation";

  const bool has_expected = (bool)test_output.expected;
  const bool has_result = (bool)test_output.result;
  const bool has_explanation = test_explanation != "TODO" &&
                               !test_explanation.empty();

  size_t max_col_size = has_explanation ? explanation_str.size() :
                        has_expected ? expected_str.size() :
                        has_result ? result_str.size() :
                        0;

  for (auto& arg : arg_names) {
    if (arg.size() > max_col_size)
      max_col_size = arg.size();
  }

  for (unsigned int i = 0; i < arguments.size(); ++i) {
    std::cout << '\t' << arg_names[i] << ": "
              << GenSpaces(max_col_size - arg_names[i].size())
              << EscapeNewline{arguments[i]} << std::endl;
  }


  if (has_expected) {
    std::cout << '\t' << expected_str << ": "
              << GenSpaces(max_col_size - expected_str.size());
    EpiPrint(std::cout, *test_output.expected);
    std::cout << std::endl;
  }
  if (has_result) {
    std::cout << '\t' << result_str << ": "
              << GenSpaces(max_col_size - result_str.size());
    EpiPrint(std::cout, *test_output.result);
    std::cout << std::endl;
  }
  if (has_explanation) {
    std::cout << '\t' << explanation_str << ": "
              << GenSpaces(max_col_size - explanation_str.size())
              << test_explanation << std::endl;
  }
}
