#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

double FindSalaryCap(int target_payroll, vector<int> current_salaries) {
  // TODO - you fill in here.
  return 0.0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"target_payroll", "current_salaries"};
  return GenericTestMain(args, "find_salary_threshold.cc",
                         "find_salary_threshold.tsv", &FindSalaryCap,
                         DefaultComparator{}, param_names);
}
