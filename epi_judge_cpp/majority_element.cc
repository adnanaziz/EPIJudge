#include <string>
#include <vector>

using std::string;
using std::vector;

string MajoritySearch(vector<string>::const_iterator stream_begin,
                      const vector<string>::const_iterator stream_end) {
  // Implement this placeholder.
  return "";
}

string MajoritySearchWrapper(const vector<string>& stream) {
  return MajoritySearch(cbegin(stream), cend(stream));
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"stream"};
  generic_test_main(argc, argv, param_names, "majority_element.tsv",
                    &MajoritySearchWrapper);
  return 0;
}
