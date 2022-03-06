#include <stdexcept>
#include <vector>
#include<bitset>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
using std::invalid_argument;
using std::vector;

int FindMissingElement(vector<int>::const_iterator stream_begin,
                       const vector<int>::const_iterator& stream_end) {
    int kBucketSize = 1 << 16;
    vector<int> counter(kBucketSize, 0);
    vector<int>::const_iterator iter = stream_begin;
    int count = 0;
    for (vector<int>::const_iterator iter = stream_begin; iter != stream_end; iter++) {
        int upper_part = (*iter) >> 16;
        ++counter[upper_part];
    }
    
    int contain_index = 0;
    const int kAllUpperCombination = 1 << 16;

    for (int i = 0; i < kAllUpperCombination; i++) {
        if (counter[i] == 0) {
            contain_index = i;
            break;
        }
    }

    std::bitset<kAllUpperCombination> bit_vec;
    for (vector<int>::const_iterator iter = stream_begin; iter != stream_end; iter++) {
        int upper_part = (*iter) >> 16;
        if (upper_part == contain_index) {
            int lower_part = ((1 << 16) - 1) & (*iter);
            bit_vec.set(lower_part);
        }
    }

    for (int i = 0; i < bit_vec.size(); i++) {
        if (bit_vec[i] == 0)
            return (contain_index << 16) | i;
    }
}
void FindMissingElementWrapper(const vector<int>& stream) {
  try {
    int res = FindMissingElement(cbegin(stream), cend(stream));
    if (std::find(stream.begin(), stream.end(), res) != stream.end()) {
      throw TestFailure(std::to_string(res) + " appears in stream");
    }
  } catch (invalid_argument&) {
    throw TestFailure("Unexpected no missing element exception");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"stream"};
  return GenericTestMain(args, "absent_value_array.cc",
                         "absent_value_array.tsv", &FindMissingElementWrapper,
                         DefaultComparator{}, param_names);
}
