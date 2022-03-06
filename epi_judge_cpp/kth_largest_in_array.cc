#include <vector>
#include <random>

#include "test_framework/generic_test.h"
using std::vector;

int PartitionAroundPivot(int left, int right, int partition_index, vector<int>* A_ptr) {
    vector<int>& A = *A_ptr;
    int new_partition_index = left;
    int partition_val = A[partition_index];
    std::swap(A[partition_index], A[right]);

    while (left < right) {
        if (A[left] >= partition_val) {
            std::swap(A[left], A[new_partition_index]);
            new_partition_index++;
        }
        left++;
    }
    std::swap(A[new_partition_index], A[right]);
    return new_partition_index;

}

int FindKthLargetHelper(int left, int right, int k, vector<int>* A_ptr) {
    vector<int>& A = *(A_ptr);

    std::default_random_engine gen((std::random_device())());
    while (left <= right) {
        int partition_index = std::uniform_int_distribution<int>{ left, right }(gen);
        int new_partition_index = PartitionAroundPivot(left, right, partition_index, &A);
        
        if (new_partition_index == k - 1) {
            return A[new_partition_index];
        }
        else if (new_partition_index > k - 1) {
            right = new_partition_index - 1;
        }
        else
            left = new_partition_index + 1;
    }
}


// The numbering starts from one, i.e., if A = [3, 1, -1, 2] then
// FindKthLargest(1, A) returns 3, FindKthLargest(2, A) returns 2,
// FindKthLargest(3, A) returns 1, and FindKthLargest(4, A) returns -1.
int FindKthLargest(int k, vector<int>* A_ptr) {
    return FindKthLargetHelper(0, (*A_ptr).size() - 1, k, A_ptr);
}
int FindKthLargestWrapper(int k, vector<int>& A) {
  return FindKthLargest(k, &A);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"k", "A"};
  return GenericTestMain(args, "kth_largest_in_array.cc",
                         "kth_largest_in_array.tsv", &FindKthLargestWrapper,
                         DefaultComparator{}, param_names);
}
