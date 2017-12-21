#include <vector>

using std::vector;

double FindSalaryCap(int target_payroll, vector<int> current_salaries) {
  // Implement this placeholder.
  return 0.0;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "find_salary_threshold.tsv", &FindSalaryCap);
  return 0;
}
