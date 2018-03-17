#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

int NumCombinationsForFinalScore(int final_score,
                                 const vector<int>& individual_play_scores) {
  // Implement this placeholder.
  return 0;
}

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"final_score", "individual_play_scores"};
  return GenericTestMain(
      args, timeout_seconds, "number_of_score_combinations.tsv",
      &NumCombinationsForFinalScore, DefaultComparator{}, param_names);
}
