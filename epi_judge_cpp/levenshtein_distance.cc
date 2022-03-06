#include <string>
#include <vector>

#include "test_framework/generic_test.h"
using std::string;
using std::vector;

int ComputeDistanceBetweenPrefixes(const string& A, int A_indx, const string& B,
    int B_indx, vector<vector<int>>& distance_btn_prefixes) {

    if (A_indx < 0)
        return B_indx + 1;
    if (B_indx < 0)
        return A_indx + 1;

    if (distance_btn_prefixes[A_indx][B_indx] == -1) {
        if(A[A_indx] == B[B_indx] ){
            distance_btn_prefixes[A_indx][B_indx] = ComputeDistanceBetweenPrefixes(A, A_indx - 1, B, B_indx - 1, distance_btn_prefixes);
        }
        else {
            int subsitute_last = ComputeDistanceBetweenPrefixes(A, A_indx - 1, B, B_indx- 1, distance_btn_prefixes);
            int add_last = ComputeDistanceBetweenPrefixes(A, A_indx - 1, B, B_indx, distance_btn_prefixes);
            int delete_last = ComputeDistanceBetweenPrefixes(A, A_indx, B, B_indx - 1, distance_btn_prefixes);
            
            distance_btn_prefixes[A_indx][B_indx] = 1 + std::min({ subsitute_last, add_last, delete_last });
        }
    }

    return distance_btn_prefixes[A_indx][B_indx];
}

int LevenshteinDistance(const string& A, const string& B) {
    vector<vector<int>> distance_btn_prefixes(A.size(), vector<int>(B.size(), -1));
    return ComputeDistanceBetweenPrefixes(A, A.size() -1, B, B.size() -1, distance_btn_prefixes);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(args, "levenshtein_distance.cc",
                         "levenshtein_distance.tsv", &LevenshteinDistance,
                         DefaultComparator{}, param_names);
}
