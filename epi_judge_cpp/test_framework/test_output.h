#pragma once

#include <experimental/optional>

#include "test_timer.h"
#include "test_utils_meta.h"

template <typename ExpectedT, typename ResultT>
struct TestOutput {
  bool comparison_result = false;
  TestTimer timer;
  std::experimental::optional<escape_void_t<ExpectedT>> expected;
  std::experimental::optional<escape_void_t<ResultT>> result;
};
