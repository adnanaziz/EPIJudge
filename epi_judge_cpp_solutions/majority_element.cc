#include <string>
#include <vector>

#include "test_framework/generic_test.h"

using std::string;
using std::vector;

string MajoritySearch(vector<string>::const_iterator stream_begin,
                      const vector<string>::const_iterator stream_end) {
  string candidate;
  int candidate_count = 0;
  while (stream_begin != stream_end) {
    string it = *stream_begin++;
    if (candidate_count == 0) {
      candidate = it;
      candidate_count = 1;
    } else if (candidate == it) {
      ++candidate_count;
    } else {
      --candidate_count;
    }
  }
  return candidate;
}

string MajoritySearchWrapper(const vector<string>& stream) {
  return MajoritySearch(cbegin(stream), cend(stream));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"stream"};
  return GenericTestMain(args, "majority_element.cc", "majority_element.tsv",
                         &MajoritySearchWrapper, DefaultComparator{},
                         param_names);
}
