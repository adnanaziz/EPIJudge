
#pragma once

#include <chrono>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

#include "platform.h"
#include "test_utils.h"
#include "tri_bool.h"

namespace test_framework {
namespace test_config {
std::string GetParam(const std::vector<std::string>& commandline_args,
                     size_t i, const char* arg_name) {
  if (i >= commandline_args.size()) {
    throw std::runtime_error(
        FmtStr("CL: Missing parameter for {}", arg_name));
  }

  return commandline_args[i];
}

void PrintUsageAndExit() {
  const char* usage_string =
      ""
      "usage: <program name> [-h] [--test-data-dir [TEST_DATA_DIR]] "
      "                      [--force-tty] [--no-tty] [--force-color] "
      "[--no-color]\n"
      "\n"
      "optional arguments:\n"
      "  -h, --help            show this help message and exit\n"
      "  --test-data-dir [TEST_DATA_DIR] path to test_data directory\n"
      "  --force-tty           enable tty features (like printing output on "
      "the same line) even in case stdout is not a tty device\n"
      "  --no-tty              never use tty features\n"
      "  --force-color         enable colored output even in case stdout is "
      "not a tty device\n"
      "  --no-color            never use colored output\n";
  std::cout << usage_string;
  exit(0);
}
}  // namespace test_config

struct TestConfig {
  TestConfig(const std::string& test_file, const std::string& test_data_file,
             const std::chrono::seconds& timeout_seconds,
             int num_failed_tests_before_stop)
      : test_file(test_file),
        test_data_file(test_data_file),
        tty_mode(TriBool::kIndeterminate),
        color_mode(TriBool::kIndeterminate),
        update_js(true),
        timeout_seconds(timeout_seconds),
        num_failed_tests_before_stop(num_failed_tests_before_stop),
        analyze_complexity(false),
        complexity_timeout(20),
        metric_names_override(
            [](const std::vector<std::string>& names) { return names; }),
        metrics_override(nullptr) {}

  static TestConfig FromCommandLine(
      const std::string& test_file, const std::string& test_data_file,
      const std::chrono::seconds& timeout_seconds,
      int num_failed_tests_before_stop,
      const std::vector<std::string>& commandline_args) {
    // Set num_failed_tests_before_stop to 0, means users want to run as many
    // as tests in one run.
    if (num_failed_tests_before_stop == 0) {
      num_failed_tests_before_stop = std::numeric_limits<int>::max();
    }

    TestConfig config{test_file, test_data_file, timeout_seconds,
                      num_failed_tests_before_stop};

    for (size_t i = 0; i < commandline_args.size(); i++) {
      if (commandline_args[i] == "--test-data-dir") {
        config.test_data_dir =
            test_config::GetParam(commandline_args, ++i, "--test-data-dir");
      } else if (commandline_args[i] == "--force-tty") {
        config.tty_mode = TriBool::kTrue;
      } else if (commandline_args[i] == "--no-tty") {
        config.tty_mode = TriBool::kFalse;
      } else if (commandline_args[i] == "--force-color") {
        config.color_mode = TriBool::kTrue;
      } else if (commandline_args[i] == "--no-color") {
        config.color_mode = TriBool::kFalse;
      } else if (commandline_args[i] == "--no-update-js") {
        config.update_js = false;
      } else if (commandline_args[i] == "--no-complexity") {
        config.analyze_complexity = false;
      } else if (commandline_args[i] == "--help" ||
                 commandline_args[i] == "-h") {
        test_config::PrintUsageAndExit();
      } else {
        throw std::runtime_error("CL: Unrecognized argument: " +
                                 commandline_args[i]);
      }
    }

    if (!config.test_data_dir.empty()) {
      if (!platform::IsDir(config.test_data_dir.c_str())) {
        throw std::runtime_error(
            FmtStr("CL: --test_data_dir argument ({}) is not a directory",
                   config.test_data_dir));
      }
    } else {
      config.test_data_dir = GetDefaultTestDataDirPath();
    }

    if (config.test_data_dir.back() != '/') {
      config.test_data_dir += '/';
    }

    return config;
  }

  std::string test_data_dir;
  std::string test_file;
  std::string test_data_file;
  TriBool tty_mode;
  TriBool color_mode;
  bool update_js;
  std::chrono::seconds timeout_seconds;
  int num_failed_tests_before_stop;
  bool analyze_complexity;
  std::chrono::seconds complexity_timeout;

  std::function<std::vector<std::string>(const std::vector<std::string>&)>
      metric_names_override;

  // Real metrics_override signature must be
  // vector<int> metrics(*)(vector<int> metrics,
  //                        std::tuple<test function args...>& func_args)
  // Since TestConfig is unaware of the tested function signature,
  // we're quite limited on possible storage types
  // for a functions that directly depends on this signature.
  using metrics_override_t = std::vector<int> (*)(
      const std::vector<int>& metrics, const std::tuple<>& func_args);
  metrics_override_t metrics_override;
};
}  // namespace test_framework

using test_framework::TestConfig;
