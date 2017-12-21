#include <iterator>
#include <string>
#include <vector>

using std::string;
using std::vector;

// Finds the candidates which may occur > n / k times.
vector<string> SearchFrequentItems(
    int k, vector<string>::const_iterator stream_begin,
    const vector<string>::const_iterator stream_end) {
  // Implement this placeholder.
  return {};
}

vector<string> SearchFrequentItemsWrapper(int k, vector<string>& v) {
  return SearchFrequentItems(k, begin(v), end(v));
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "search_frequent_items.tsv",
                    &SearchFrequentItemsWrapper,
                    &UnorderedComparator<std::vector<std::string>>);
  return 0;
}
