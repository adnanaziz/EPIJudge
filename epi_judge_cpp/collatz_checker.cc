#include <vector>
#include <unordered_set>

#include "test_framework/generic_test.h"
using std::vector;

bool TestCollatzConjecture(int n) {
  
    std::unordered_set<long long> validated_numbers;
    for (long long i = 3; i <= n; i += 2) {
        long long t_num = i;
        std::unordered_set<long long> sequence;

        while(t_num >= i){
            if (sequence.count(t_num)) {
                return false;
            }

            if (t_num % 2) {
                long long new_num = t_num * 3 + 1;
                if (new_num <= t_num) 
                    throw std::overflow_error("Collatz number overflow for "+ std::to_string(i));

                t_num = new_num;
            }
            else {
                t_num /= 2;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "collatz_checker.cc", "collatz_checker.tsv",
                         &TestCollatzConjecture, DefaultComparator{},
                         param_names);
}
