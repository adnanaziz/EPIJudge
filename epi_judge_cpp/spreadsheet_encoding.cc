#include <string>

using std::string;

int SSDecodeColID(const string& col) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"col"};
  generic_test_main(argc, argv, param_names, "spreadsheet_encoding.tsv",
                    &SSDecodeColID);
  return 0;
}
