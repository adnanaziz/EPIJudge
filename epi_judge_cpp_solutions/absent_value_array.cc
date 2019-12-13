#include <bitset>
#include <stdexcept>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"

using std::bitset;
using std::invalid_argument;
using std::vector;

int FindMissingElement(vector<int>::const_iterator stream_begin,
                       const vector<int>::const_iterator& stream_end) {
  const int kNumBucket = 1 << 16;
  vector<size_t> counter(kNumBucket, 0);
  vector<int>::const_iterator stream_begin_copy = stream_begin;
  while (stream_begin != stream_end) {
    int upper_part_x = *stream_begin >> 16;
    ++counter[upper_part_x];
    ++stream_begin;
  }

  // Look for a bucket that contains less than (1 << 16) elements.
  const int kBucketCapacity = 1 << 16;
  int candidate_bucket = 0;
  for (int i = 0; i < kNumBucket; ++i) {
    if (counter[i] < kBucketCapacity) {
      candidate_bucket = i;
      break;
    }
  }

  // Finds all IP addresses in the stream whose first 16 bits
  // are equal to candidate_bucket.
  bitset<kBucketCapacity> candidates;
  stream_begin = stream_begin_copy;
  while (stream_begin != stream_end) {
    int x = *stream_begin++;
    if (int upper_part_x = x >> 16; candidate_bucket == upper_part_x) {
      // Records the presence of 16 LSB of x.
      int lower_part_x = ((1 << 16) - 1) & x;
      candidates.set(lower_part_x);
    }
  }

  // At least one of the LSB combinations is absent, find it.
  for (int i = 0; i < kBucketCapacity; ++i) {
    if (candidates[i] == 0) {
      return (candidate_bucket << 16) | i;
    }
  }

  throw invalid_argument("no missing element");
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
