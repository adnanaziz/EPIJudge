#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

struct ABSqrt2{
    ABSqrt2(int a, int b):a(a), b(b), value(a + b*sqrt(2)){}

    bool operator <(const ABSqrt2& that) const {
        return value < that.value;
    }

    bool operator ==(const ABSqrt2& that) const {
        return value == that.value;
    }

    int a, b;
    double value;
};

vector<double>  GenerateFirstKABSqrt2Type1(int k) {
    vector<double> results;

    std::set<ABSqrt2> sqrtValues;
    sqrtValues.emplace(0, 0);

    while (results.size() < k) {
        auto iter = sqrtValues.cbegin();
        results.push_back(iter->value);

        sqrtValues.emplace(iter->a + 1, iter->b);
        sqrtValues.emplace(iter->a, iter->b + 1);

        sqrtValues.erase(iter);
    }
    return results;
}

vector<double>  GenerateFirstKABSqrt2Type2(int k) {
    vector<double> results;

    vector<ABSqrt2> sqrtValues;
    sqrtValues.emplace_back(0, 0);
    int i = 0, j = 0;

    results.emplace_back(sqrtValues.crbegin()->value);
    while (results.size() < k) {
        auto iter = sqrtValues.cbegin();
        
        ABSqrt2 result_plus_1 { sqrtValues[i].a +1, sqrtValues[i].b};
        ABSqrt2 result_plus_1_sqrt2{ sqrtValues[j].a, sqrtValues[j].b + 1};

        sqrtValues.emplace_back(std::min(result_plus_1, result_plus_1_sqrt2));
        if (*(sqrtValues.crbegin()) == result_plus_1) {
            i++;
        }

        if (*sqrtValues.crbegin() == result_plus_1_sqrt2) {
            j++;
        }
        results.emplace_back(sqrtValues.crbegin()->value);
    }
    return results;
}

vector<double> GenerateFirstKABSqrt2(int k) {
    return GenerateFirstKABSqrt2Type2(k);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"k"};
  return GenericTestMain(args, "a_b_sqrt2.cc", "a_b_sqrt2.tsv",
                         &GenerateFirstKABSqrt2, DefaultComparator{},
                         param_names);
}
