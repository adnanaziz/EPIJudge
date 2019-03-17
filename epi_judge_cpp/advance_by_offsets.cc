#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
// bool CanReachEnd(const vector<int>& A) {
//     int n = A.size();
//     if (n == 1) return true;

//     vector<bool> reach(n, false);
//     reach[n-1] = true;

//     for (int i=n-2; i>=0; i--)
//     {
//         for (int j=i; j<i+A[i]+1; j++)
//         {
//             if (reach[j] == true)
//             {
//                 reach[i] = true;
//                 break;
//             }
//         }
//     }

//     return reach[0];
// }

bool CanReachEnd(const vector<int>& A) {
    int n = A.size();
    if (n == 1) return true;
    vector<int> reach(n, 0);
    int max_till_now = 0;

    for (int i=0; i<n; i++)
    {
        if (i > max_till_now) return false;
        reach[i] = std::max(A[i]+i, max_till_now);
        if (reach[i] > max_till_now) max_till_now = reach[i];
        if (max_till_now == n-1) return true;
    }
    return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"max_advance_steps"};
  return GenericTestMain(args, "advance_by_offsets.cc",
                         "advance_by_offsets.tsv", &CanReachEnd,
                         DefaultComparator{}, param_names);
}
