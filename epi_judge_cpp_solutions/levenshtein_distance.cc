#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "test_framework/generic_test.h"

using std::make_unique;
using std::min;
using std::string;
using std::vector;

int ComputeDistanceBetweenPrefixes(const string&, int, const string&, int,
                                   vector<vector<int>>*);

int LevenshteinDistance(const string& A, const string& B) {
  vector<vector<int>> distance_between_prefixes(size(A),
                                                vector<int>(size(B), -1));
  return ComputeDistanceBetweenPrefixes(
      A, size(A) - 1, B, size(B) - 1,
      make_unique<vector<vector<int>>>(size(A), vector<int>(size(B), -1))
          .get());
}

int ComputeDistanceBetweenPrefixes(
    const string& A, int A_idx, const string& B, int B_idx,
    vector<vector<int>>* distance_between_prefixes_ptr) {
  vector<vector<int>>& distance_between_prefixes =
      *distance_between_prefixes_ptr;
  if (A_idx < 0) {
    // A is empty so add all of B's characters.
    return B_idx + 1;
  } else if (B_idx < 0) {
    // B is empty so delete all of A's characters.
    return A_idx + 1;
  }
  if (distance_between_prefixes[A_idx][B_idx] == -1) {
    if (A[A_idx] == B[B_idx]) {
      distance_between_prefixes[A_idx][B_idx] = ComputeDistanceBetweenPrefixes(
          A, A_idx - 1, B, B_idx - 1, distance_between_prefixes_ptr);
    } else {
      int substitute_last = ComputeDistanceBetweenPrefixes(
          A, A_idx - 1, B, B_idx - 1, distance_between_prefixes_ptr);
      int add_last = ComputeDistanceBetweenPrefixes(
          A, A_idx, B, B_idx - 1, distance_between_prefixes_ptr);
      int delete_last = ComputeDistanceBetweenPrefixes(
          A, A_idx - 1, B, B_idx, distance_between_prefixes_ptr);
      distance_between_prefixes[A_idx][B_idx] =
          1 + min({substitute_last, add_last, delete_last});
    }
  }
  return distance_between_prefixes[A_idx][B_idx];
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(args, "levenshtein_distance.cc",
                         "levenshtein_distance.tsv", &LevenshteinDistance,
                         DefaultComparator{}, param_names);
}
