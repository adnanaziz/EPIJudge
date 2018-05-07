#include <iterator>
#include <string>
#include <vector>
#include "test_framework/generic_test.h"
using std::string;
using std::vector;

// Finds the candidates which may occur > n / k times.
vector<string> SearchFrequentItems(
    int k, vector<string>::const_iterator stream_begin,
    const vector<string>::const_iterator stream_end) {
  // TODO - you fill in here.
  return {};
}
vector<string> SearchFrequentItemsWrapper(int k, vector<string>& stream) {
  return SearchFrequentItems(k, begin(stream), end(stream));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"k", "stream"};
  return GenericTestMain(
      args, "search_frequent_items.cc", "search_frequent_items.tsv",
      &SearchFrequentItemsWrapper,
      &UnorderedComparator<std::vector<std::string>>, param_names);
}
