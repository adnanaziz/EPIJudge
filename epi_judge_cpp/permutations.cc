#include <vector>

#include "test_framework/generic_test.h"
using std::vector;


bool NextPermutation(vector<int>& A) {
    int k = A.size() - 2;
    for (int i = A.size() - 2; i >= 0 && A[i] > A[i + 1]; i--)
        k--;

    if (k == -1)
        return false;

    for (int j = A.size() - 1; j > k; j--) {
        if (A[j] > A[k]) {
            std::swap(A[j], A[k]);
            break;
        }
    }

    std::reverse(A.begin() + k + 1, A.end());
    return true;
}

void PermutationHelper(vector<int> A, int indx, vector<vector<int>>& results) {
    if (indx == A.size() - 1) {
        results.push_back(A);
        return;
    }

    for (int j = indx; j < A.size(); j++) {
        std::swap(A[indx], A[j]);
        PermutationHelper(A, indx + 1, results);
        std::swap(A[indx], A[j]);
    }
}

vector<vector<int>> Permutations(vector<int> A) {
    vector<vector<int>> results;
    //Method:01
    //PermutationHelper(A, 0, results);
    
    std::sort(A.begin(), A.end());
    do {
        results.push_back(A);
    } while (NextPermutation(A));

    return results;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "permutations.cc", "permutations.tsv",
                         &Permutations, UnorderedComparator{}, param_names);
}
