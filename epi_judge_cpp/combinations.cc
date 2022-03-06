#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

void DirectedCombinations(int n, int k, int indx, vector<int>* combinations, vector<vector<int>>& results) {
    if (combinations->size() == k) {
        results.push_back(*combinations);
        return;
    }
    
    int nRemaining = k - combinations->size();
    for (int i = indx; i <= n && nRemaining <= n - i + 1; i++) {
        combinations->push_back(i);
        DirectedCombinations(n, k, i + 1, combinations, results);
        combinations->pop_back();
    }

}

vector<vector<int>> Combinations(int n, int k) {
    vector<vector<int>> results;
    DirectedCombinations(n, k, 1, new vector<int>, results);
    return results;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n", "k"};
  return GenericTestMain(args, "combinations.cc", "combinations.tsv",
                         &Combinations, UnorderedComparator{}, param_names);
}
