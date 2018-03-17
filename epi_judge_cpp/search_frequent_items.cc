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
  // Implement this placeholder.
  return {};
}

vector<string> SearchFrequentItemsWrapper(int k, vector<string>& stream) {
  return SearchFrequentItems(k, begin(stream), end(stream));
}

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"k", "stream"};
  return GenericTestMain(args, timeout_seconds, "search_frequent_items.tsv",
                         &SearchFrequentItemsWrapper,
                         &UnorderedComparator<std::vector<std::string>>,
                         param_names);
}
