#include <vector>
#include <random>

#include "test_framework/generic_test.h"
using std::vector;

template <typename Compare>
int PartitionAroundPivot(int left, int right, int pivot_indx, Compare comp, vector<int>& result) {
    int new_pivot_index = left;
    int pivot_value = result[pivot_indx];

    std::swap(result[pivot_indx], result[right]);
    for (int i = left; i < right; i++) {
        if (comp(result[i], pivot_value)) {
            std::swap(result[i], result[new_pivot_index++]);
        }
    }
    std::swap(result[right], result[new_pivot_index]);
    return new_pivot_index;
}

template <typename Compare>
int FindKth(vector<int>& result, int k, Compare comp) {
    int left = 0, right = result.size()-1;
    std::default_random_engine gen((std::random_device())());

    while (left <= right) {
        int pivot_indx = std::uniform_int_distribution<int>{ left, right }(gen);
        int new_pivot_index = PartitionAroundPivot(left, right, pivot_indx, comp, result);

        if (new_pivot_index == k - 1) {
            return new_pivot_index;
        }
        else if (new_pivot_index < k-1) {
            left = new_pivot_index + 1;
        }
        else {
            right = new_pivot_index - 1;
        }
    
    }
}

int FindKthLargestUnknownLength(vector<int>::const_iterator stream_begin,
                                const vector<int>::const_iterator& stream_end,
                                int k) {
    vector<int> result;
    for (vector<int>::const_iterator iter = stream_begin; iter != stream_end; iter++) {
        result.push_back(*iter);
        if (result.size() == k*2-1) {
            FindKth(result, k, std::greater<int>());
            result.resize(k);
        }
    }

    FindKth(result, k, std::greater<int>());
    return result[k-1];
}

int FindKthLargestUnknownLengthWrapper(const vector<int>& stream, int k) {
  return FindKthLargestUnknownLength(stream.cbegin(), stream.cend(), k);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"stream", "k"};
  return GenericTestMain(args, "kth_largest_element_in_long_array.cc",
                         "kth_largest_element_in_long_array.tsv",
                         &FindKthLargestUnknownLengthWrapper,
                         DefaultComparator{}, param_names);
}
