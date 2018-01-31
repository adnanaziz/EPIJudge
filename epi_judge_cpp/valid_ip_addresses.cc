#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> GetValidIpAddress(const string& s) {
  // Implement this placeholder.
  return {};
}

bool comp(vector<string> expected, vector<string> result) {
  std::sort(begin(expected), end(expected));
  std::sort(begin(result), end(result));
  return expected == result;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"s"};
  generic_test_main(argc, argv, param_names, "valid_ip_addresses.tsv",
                    &GetValidIpAddress, &comp);
  return 0;
}
