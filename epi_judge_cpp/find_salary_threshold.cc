#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

double FindSalaryCap(int target_payroll, vector<int> current_salaries) {
    std::sort(current_salaries.begin(), current_salaries.end());

    double unadjusted_salary = 0;
    
    for (int i = 0; i < current_salaries.size(); i++) {
        double adjusted_salary = (current_salaries[i]) * (current_salaries.size() - i);

        if (target_payroll >= adjusted_salary + unadjusted_salary) {
            return (target_payroll - unadjusted_salary) / (adjusted_salary);
        }
        unadjusted_salary += current_salaries[i];
    }
    return -1.0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"target_payroll", "current_salaries"};
  return GenericTestMain(args, "find_salary_threshold.cc",
                         "find_salary_threshold.tsv", &FindSalaryCap,
                         DefaultComparator{}, param_names);
}
