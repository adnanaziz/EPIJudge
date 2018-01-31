#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> PhoneMnemonic(const string& phone_number) {
  // Implement this placeholder.
  return {};
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"phone_number"};
  generic_test_main(argc, argv, param_names, "phone_number_mnemonic.tsv",
                    &PhoneMnemonic,
                    &UnorderedComparator<std::vector<std::string>>);
  return 0;
}
