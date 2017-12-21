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

int FindMissingElementWrapper(const vector<int>& data) {
  try {
    return FindMissingElement(cbegin(data), cend(data));
  } catch (invalid_argument&) {
    throw TestFailureException("Unexpected no_missing_element exception");
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "absent_value_array.tsv",
                    &FindMissingElementWrapper);
  return 0;
}
