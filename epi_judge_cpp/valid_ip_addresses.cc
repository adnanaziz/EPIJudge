#include <algorithm>
#include <string>
#include <vector>
#include "test_framework/generic_test.h"

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

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, timeout_seconds, "valid_ip_addresses.tsv",
                         &GetValidIpAddress, &comp, param_names);
}
