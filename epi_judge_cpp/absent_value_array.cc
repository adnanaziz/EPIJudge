#include <stdexcept>
#include <vector>

#include "test_framework/test_failure_exception.h"

using std::invalid_argument;
using std::vector;

int FindMissingElement(vector<int>::const_iterator stream_begin,
                       const vector<int>::const_iterator& stream_end) {
  // Implement this placeholder.
  return 0;
}

int FindMissingElementWrapper(const vector<int>& stream) {
  try {
    return FindMissingElement(cbegin(stream), cend(stream));
  } catch (invalid_argument&) {
    throw TestFailureException("Unexpected no_missing_element exception");
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"stream"};
  generic_test_main(argc, argv, param_names, "absent_value_array.tsv",
                    &FindMissingElementWrapper);
  return 0;
}
