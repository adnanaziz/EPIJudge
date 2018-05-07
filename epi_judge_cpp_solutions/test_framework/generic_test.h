
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
#include "json_parser.h"
#include "platform.h"
#include "test_config.h"
#include "test_timer.h"
#include "test_utils.h"

template <typename Function, typename Comparator>
TestResult RunTests(GenericTestHandler<Function, Comparator>& handler,
                    const TestConfig& config);

/**
 * The main test starter.
 */
template <typename Function, typename Comparator>
TestResult GenericTestMain(const std::vector<std::string>& commandline_args,
                           const std::string& test_file,
                           const std::string& test_data_file,
                           Function test_func, Comparator comparator,
                           const std::vector<std::string>& param_names) {
  std::ifstream config_data(GetFilePathInJudgeDir("config.json"));
  std::stringstream buffer;
  buffer << config_data.rdbuf();
  std::string err;
  const json_parser::Json config_override =
      json_parser::Json::parse(buffer.str(), err);

  // Enables automatic flushing of the output stream after any output
  // operation.
  std::cout.setf(std::ios::unitbuf);

  try {
    TestConfig config = TestConfig::FromCommandLine(
        test_file, test_data_file,
        std::chrono::seconds{config_override["timeoutSeconds"].int_value()},
        (int)config_override["numFailedTestsBeforeStop"].int_value(),
        commandline_args);

    platform::SetOutputOpts(config.tty_mode, config.color_mode);

    GenericTestHandler<Function, Comparator> test_handler(
        test_func, comparator, param_names);
    return RunTests(test_handler, config);
  } catch (std::runtime_error& e) {
    std::cerr << std::endl << "Critical error: " << e.what() << std::endl;
    return RUNTIME_ERROR;
  }
}

void UpdateTestPassed(std::string test_file, int tests_passed) {
  const std::string problem_mapping_file_path =
      GetFilePathInJudgeDir("problem_mapping.js");
  std::ifstream problem_mapping_file_data(problem_mapping_file_path);
  std::stringstream buffer;
  buffer << problem_mapping_file_data.rdbuf();
  std::string err;
  std::string js_file_str = buffer.str();
  const std::string kJsBeginPattern = "run(";
  js_file_str.replace(js_file_str.find(kJsBeginPattern),
                      kJsBeginPattern.size(), "");
  const std::string kJsEndPattern = ");";
  js_file_str.replace(js_file_str.find(kJsEndPattern), kJsEndPattern.size(),
                      "");
  const json_parser::Json chapter_to_problem_to_language_solution_mapping =
      json_parser::Json::parse(js_file_str, err);

  test_file = "C++: " + test_file;
  std::string serialized_problem_mapping =
      chapter_to_problem_to_language_solution_mapping.dump();
  for (const auto& chapter :
       chapter_to_problem_to_language_solution_mapping.object_items()) {
    for (const auto& problem : chapter.second.object_items()) {
      for (const auto& language : problem.second.object_items()) {
        if (test_file == language.first) {
          const std::string format = "\"{}\": {{\"passed\": {},";
          const std::string pattern = FmtStr(
              format, test_file, language.second["passed"].int_value());
          const std::string replacement =
              FmtStr(format, test_file, tests_passed);
          serialized_problem_mapping.replace(
              serialized_problem_mapping.find(pattern), pattern.size(),
              replacement);
          std::ofstream ofs(problem_mapping_file_path);
          ofs << kJsBeginPattern << serialized_problem_mapping
              << kJsEndPattern;
          ofs.close();
          return;
        }
      }
    }
  }
}

template <typename Function, typename Comparator>
TestResult RunTests(GenericTestHandler<Function, Comparator>& handler,
                    const TestConfig& config) {
  std::vector<std::vector<std::string>> test_data =
      SplitTsvFile(config.test_data_dir + config.test_data_file);
  handler.ParseSignature(test_data[0]);

  int test_nr = 0;
  int tests_passed = 0;
  const int total_tests = static_cast<int>(test_data.size() - 1);
  std::vector<std::vector<int>> metrics;
  std::vector<std::chrono::microseconds> durations;
  TestResult result = FAILED;

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
      test_output = handler.RunTest(config.timeout_seconds, test_case);
      result = PASSED;
      ++tests_passed;
      metrics.emplace_back(test_output.metrics);
      durations.emplace_back(test_output.timer.GetMicroseconds());
    } catch (TestFailure& e) {
      result = FAILED;
      test_failure = e;
    } catch (TimeoutException& e) {
      result = TIMEOUT;
      test_output.timer = e.GetTimer();
    } catch (std::runtime_error&) {
      throw;
    } catch (std::exception& e) {
      result = UNKNOWN_EXCEPTION;
      test_failure = TestFailure(typeid(e).name())
                         .WithProperty(PropertyName::EXCEPTION_MESSAGE,
                                       std::string(e.what()));
    } catch (...) {
      result = UNKNOWN_EXCEPTION;
      test_failure = TestFailure("Can't get exception information");
    }

    PrintTestInfo(result, test_nr, total_tests, test_failure.GetDescription(),
                  test_output.timer);

    if (result != PASSED) {
      if (config.verbose) {
        if (!handler.ExpectedIsVoid()) {
          test_case.pop_back();
        }
        if (test_explanation != "TODO" && !test_explanation.empty()) {
          test_failure.WithProperty(PropertyName::EXPLANATION,
                                    test_explanation);
        }
        PrintFailedTest(handler.ParamNames(), test_case, test_failure);
      }
      const int tests_not_passed = test_nr - tests_passed;
      if (tests_not_passed >= config.num_failed_tests_before_stop) {
        break;
      }
    }
  }

  if (config.update_js) {
    UpdateTestPassed(config.test_file, tests_passed);
  }

  std::string complexity;

  std::cout << std::endl;
  if (config.verbose) {
    PrintPostRunStats(tests_passed, total_tests, complexity, durations);
  }
  return result;
}
