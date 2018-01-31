
#include "test_framework/test_timer.h"

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"timer", "A", "rotate_amount"};
  generic_test_main(argc, argv, param_names, "rotate_array.tsv",
                    &RotateArrayWrapper);
  return 0;
}
