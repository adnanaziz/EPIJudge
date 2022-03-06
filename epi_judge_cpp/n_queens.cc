#include <algorithm>
#include <iterator>
#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

bool isValidPosition(std::unique_ptr<vector<int>>& combinations) {
    int row_id = combinations->size() - 1;
    for (int i = 0; i < row_id; i++) {
        int diff = std::abs((*combinations)[i] - (*combinations)[row_id]);
        if (diff == 0 || diff == row_id - i)
            return false;
    }
    return true;
}

void SetQueens(int n, int row_id, std::unique_ptr<vector<int>>& combinations, vector<vector<int>>& results) {
    if (combinations->size() == n) {
        results.push_back(*combinations);
        return;
    }

    for (int col = 0; col < n; col++) {
        combinations->push_back(col);
        if(isValidPosition(combinations)){
            SetQueens(n, row_id + 1, combinations, results);
        }
        combinations->pop_back();
    }

}

vector<vector<int>> NQueens(int n) {
    vector<vector<int>> results;
    SetQueens(n, 0, std::make_unique<vector<int>>(), results);
    return results;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "n_queens.cc", "n_queens.tsv", &NQueens,
                         UnorderedComparator{}, param_names);
}
