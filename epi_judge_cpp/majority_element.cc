#include <string>
#include <vector>

using std::string;
using std::vector;

string MajoritySearch(vector<string>::const_iterator input_stream_begin,
                      const vector<string>::const_iterator input_stream_end) {
  // Implement this placeholder.
  return "";
}

string MajoritySearchWrapper(const vector<string>& input_stream) {
  return MajoritySearch(cbegin(input_stream), cend(input_stream));
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "majority_element.tsv", &MajoritySearchWrapper);
  return 0;
}
