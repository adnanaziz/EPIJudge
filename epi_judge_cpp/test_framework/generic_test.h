
#pragma once

#include <chrono>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <vector>

#include "fmt_print.h"
#include "generic_test_handler.h"
#include "json.h"
#include "platform.h"
#include "test_config.h"
#include "test_timer.h"
#include "test_utils.h"

namespace test_framework {
using json = nlohmann::json;

template <typename Function, typename Comparator>
TestResult RunTests(GenericTestHandler<Function, Comparator>& handler,
                    const TestConfig& config);

/**
 * The main test starter.
 */
template <typename Function, typename Comparator>
int GenericTestMain(
    const std::vector<std::string>& commandline_args,
    const std::string& test_file, const std::string& test_data_file,
    Function test_func, Comparator comparator,
    const std::vector<std::string>& param_names,
    const std::function<void(TestConfig&)>& program_config = {}) {
  std::ifstream config_data(GetFilePathInJudgeDir("config.json"));
  json config_override;
  config_data >> config_override;

  // Enables automatic flushing of the output stream after any output
  // operation.
  std::cout.setf(std::ios::unitbuf);

  try {
    TestConfig config = TestConfig::FromCommandLine(
        test_file, test_data_file,
        std::chrono::seconds{config_override["timeoutSeconds"]},
        config_override["numFailedTestsBeforeStop"], commandline_args);

    if (program_config) {
      program_config(config);
    }

    platform::SetOutputOpts(config.tty_mode, config.color_mode);

    GenericTestHandler<Function, Comparator> test_handler(
        test_func, comparator, param_names);
    return static_cast<int>(RunTests(test_handler, config));
  } catch (std::runtime_error& e) {
    std::cerr << "\nCritical error: " << e.what() << std::endl;
    return static_cast<int>(TestResult::RUNTIME_ERROR);
  }
}

void UpdateTestPassed(std::string test_file, int tests_passed) {
  const std::string problem_mapping_file_path =
      GetFilePathInJudgeDir("problem_mapping.js");
  std::ifstream problem_mapping_file_data(problem_mapping_file_path);
  if (!problem_mapping_file_data.is_open()) {
    std::cerr << "Missing problem_mapping.js\n";
    return;
  }
  std::stringstream buffer;
  buffer << problem_mapping_file_data.rdbuf();
  std::string err;
  std::string js_file_str = buffer.str();
  const std::string kJsBeginPattern = "problem_mapping = ";
  js_file_str.replace(js_file_str.find(kJsBeginPattern),
                      kJsBeginPattern.size(), "");
  const std::string kJsEndPattern = ";";
  js_file_str.replace(js_file_str.find(kJsEndPattern), kJsEndPattern.size(),
                      "");
  try {
    json chapter_to_problem_to_language_solution_mapping =
        json::parse(js_file_str);

    test_file = "C++: " + test_file;
    for (auto& chapter :
         chapter_to_problem_to_language_solution_mapping.items()) {
      for (auto& problem : chapter.value().items()) {
        for (auto& language_solution_mapping : problem.value().items()) {
          if (test_file == language_solution_mapping.key()) {
            language_solution_mapping.value()["passed"] = tests_passed;
            std::ofstream ofs(problem_mapping_file_path);
            ofs << kJsBeginPattern;
            ofs << std::setw(4)
                << chapter_to_problem_to_language_solution_mapping;
            ofs << kJsEndPattern;
            ofs.close();
            return;
          }
        }
      }
    }
  } catch (nlohmann::detail::parse_error& e) {
    std::cerr << "Error parsing problem_mapping.js: " << e.what() << "\n";
    return;
  }
}

template <typename Function, typename Comparator>
TestResult RunTests(GenericTestHandler<Function, Comparator>& handler,
                    const TestConfig& config) {
  std::vector<std::vector<std::string>> test_data =
      SplitTsvFile(config.test_data_dir + config.test_data_file);
  handler.ParseSignature(test_data[0]);

  auto metric_names = config.metric_names_override(handler.MetricNames());

  int test_nr = 0;
  int tests_passed = 0;
  const int total_tests = static_cast<int>(test_data.size() - 1);
  std::vector<std::vector<int>> metrics;
  std::vector<std::chrono::microseconds> durations;
  TestResult result = TestResult::FAILED;

  for (auto test_case : std::vector<std::vector<std::string>>{
           test_data.begin() + 1, test_data.end()}) {
    test_nr++;

    // Since the last field of test_data is test_explanation, which is not
    // used for running test, we extract that here.
    const std::string test_explanation = std::move(test_case.back());
    test_case.pop_back();

    TestOutput test_output;
    TestFailure test_failure;

    try {
      test_output = handler.RunTest(config.timeout_seconds,
                                    config.metrics_override, test_case);
      result = TestResult::PASSED;
      ++tests_passed;
      metrics.emplace_back(test_output.metrics);
      durations.emplace_back(test_output.timer.GetMicroseconds());
    } catch (TestFailure& e) {
      result = TestResult::FAILED;
      test_failure = e;
    } catch (TimeoutException& e) {
      result = TestResult::TIMEOUT;
      test_output.timer = e.GetTimer();
    } catch (std::runtime_error&) {
      throw;
    } catch (std::exception& e) {
      result = TestResult::UNKNOWN_EXCEPTION;
      test_failure = TestFailure(typeid(e).name())
                         .WithProperty(PropertyName::EXCEPTION_MESSAGE,
                                       std::string(e.what()));
    } catch (...) {
      result = TestResult::UNKNOWN_EXCEPTION;
      test_failure = TestFailure("Can't get exception information");
    }

    PrintTestInfo(result, test_nr, total_tests, test_failure.GetDescription(),
                  test_output.timer);

    if (result != TestResult::PASSED) {
      if (!handler.ExpectedIsVoid()) {
        test_case.pop_back();
      }
      if (test_explanation != "TODO" && !test_explanation.empty()) {
        test_failure.WithProperty(PropertyName::EXPLANATION,
                                  test_explanation);
      }
      PrintFailedTest(handler.ParamNames(), test_case, test_failure);

      const int tests_not_passed = test_nr - tests_passed;
      if (tests_not_passed >= config.num_failed_tests_before_stop) {
        break;
      }
    }
  }

  if (config.update_js) {
    UpdateTestPassed(config.test_file, tests_passed);
  }

  std::cout << std::endl;
  if (!durations.empty()) {
    std::string complexity;
    if (!metric_names.empty() && !metrics.empty() &&
        config.analyze_complexity) {
      std::vector<long long> time;
      std::transform(
          durations.begin(), durations.end(), std::back_inserter(time),
          [](const auto& d) {
            return std::chrono::duration_cast<std::chrono::nanoseconds>(d)
                .count();
          });
      ShowComplexityNotification();
    }

    PrintPostRunStats(tests_passed, total_tests, complexity, durations);
  }
  return result;
}
}  // namespace test_framework
using test_framework::GenericTestMain;
