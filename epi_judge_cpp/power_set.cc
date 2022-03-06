#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

void DirectedPowerSet(const vector<int>& input_set, int indx, vector<int>* combinations, vector<vector<int>>& results) {
    if (indx == input_set.size()) {
        results.push_back(*combinations);
        return;
    }

    combinations->push_back(input_set[indx]);
    DirectedPowerSet(input_set, indx + 1, combinations, results);

    combinations->pop_back();
    DirectedPowerSet(input_set, indx + 1, combinations, results);
}
vector<vector<int>> GeneratePowerSet_Method2(const vector<int>& input_set) {
    vector<vector<int>> results;
    for (int i = 0; i < 1 << input_set.size(); i++) {
        int begin_set = i;
        vector<int> subset;
        while (begin_set) {
            subset.push_back(input_set[log2(begin_set & ~(begin_set - 1))]);
            begin_set &= begin_set - 1;
        }
        results.push_back(subset);
    }
    return results;
}

vector<vector<int>> GeneratePowerSet(const vector<int>& input_set) {
    /*Method 1
    vector<vector<int>> results;
    DirectedPowerSet(input_set, 0, new vector<int>, results);
    return results;
    */

    return GeneratePowerSet_Method2(input_set);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"input_set"};
  return GenericTestMain(args, "power_set.cc", "power_set.tsv",
                         &GeneratePowerSet, UnorderedComparator{}, param_names);
}
