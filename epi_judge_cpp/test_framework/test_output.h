// @library
#pragma once

#include <memory>

#include "test_timer.h"
#include "test_utils_meta.h"

template <typename ExpectedT, typename ResultT>
struct TestOutput {
  using expected_t = escape_void_t<ExpectedT>;
  using result_t = escape_void_t<ResultT>;

  bool comparison_result;
  TestTimer timer;
  std::unique_ptr<expected_t> expected;
  std::unique_ptr<result_t> result;

  TestOutput() : comparison_result(false) {}

  TestOutput(bool comparison, const TestTimer& t)
      : comparison_result(comparison), timer(t) {}

  TestOutput(bool comparison, const TestTimer& t, expected_t&& expected,
             result_t&& result)
      : comparison_result(comparison),
        timer(t),
        expected(std::make_unique<expected_t>(std::move(expected))),
        result(std::make_unique<result_t>(std::move(result))) {}
};
