// @library
#pragma once

#include <chrono>
#include <stdexcept>
#include <string>
#include <vector>

#include "platform.h"
#include "test_utils.h"

struct TestConfig {
  static TestConfig FromCommandLine(
      const std::string& test_data_file, const std::chrono::seconds& timeout,
      const std::vector<std::string>& commandline_args) {
    TestConfig config{"", test_data_file, true, timeout};

    for (int i = 0; i < commandline_args.size(); i++) {
      if (commandline_args[i] == "--test_data_dir") {
        if (i + 1 >= commandline_args.size()) {
          throw std::runtime_error("Missing param for --test_data_dir");
        }
        config.test_data_dir = commandline_args[i + 1];
        i++;
      } else if (commandline_args[i] == "--run_all_tests") {
        config.stop_on_error = false;
      } else {
        throw std::runtime_error("Unrecognized argument: " +
                                 commandline_args[i]);
      }
    }

    if (!config.test_data_dir.empty()) {
      if (!platform::IsDir(config.test_data_dir.c_str()))
        throw std::runtime_error("--test_data_dir argument \"" +
                                 config.test_data_dir +
                                 "\" is not a directory");
    } else {
      config.test_data_dir = GetDefaultTestDataDirPath();
    }

    if (config.test_data_dir.back() != '/') {
      config.test_data_dir += '/';
    }

    return config;
  }

  std::string test_data_dir;
  std::string test_data_file;
  bool stop_on_error;
  std::chrono::milliseconds timeout;
};
