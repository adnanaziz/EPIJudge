#include <string>

using std::string;

string ConvertBase(const string& num_as_string, int b1, int b2) {
  // Implement this placeholder.
  return "";
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "convert_base.tsv", &ConvertBase);
  return 0;
}
