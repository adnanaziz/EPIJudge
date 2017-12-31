// @library
#pragma once

#include <iomanip>
#include <iostream>
#include <string>

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
  if (UseTtyOutput()) {
    os << '\r';
  } else {
    os << '\n';
  };
}

void PrintTestResult(const TestResult& test_result, int test_nr,
                     int total_tests, const std::string& diagnostic,
                     const TestTimer& timer) {
  ReturnCaretIfTtyOutput(std::cout);

  auto total_tests_str = std::to_string(total_tests);
  std::cout << "Test " << test_result << " ("
            << std::setw(static_cast<int>(total_tests_str.size())) << test_nr
            << '/' << total_tests_str << ")";

  if (timer.HasValidResult()) {
    std::cout << " [" << DurationToString(timer.GetMicroseconds()) << "]";
  }

  if (test_result != PASSED) {
    std::cout << ' ' << diagnostic << '\n';
  }
}

template <typename TestOutputT>
void PrintFailedTest(const std::vector<std::string>& arguments,
                     const TestOutputT& test_output,
                     const std::string& test_explanation) {
  for (unsigned int i = 0; i < arguments.size(); ++i) {
    std::cout << "\tArg " << i + 1 << ": " << EscapeNewline{arguments[i]}
              << std::endl;
  }

  if (test_output.expected) {
    std::cout << "\tExpected: ";
    EpiPrint(std::cout, *test_output.expected);
    std::cout << std::endl;
  }
  if (test_output.result) {
    std::cout << "\tResult:   ";
    EpiPrint(std::cout, *test_output.result);
    std::cout << std::endl;
  }
  if (test_explanation != "TODO" && test_explanation != "") {
    std::cout << "\tExplanation: " << test_explanation << std::endl;
  }
}
