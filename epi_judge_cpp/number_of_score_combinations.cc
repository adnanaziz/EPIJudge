#include <vector>

using std::vector;

int NumCombinationsForFinalScore(int final_score,
                                 const vector<int>& individual_play_scores) {
  // Implement this placeholder.
  return 0;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"final_score", "individual_play_scores"};
  GenericTestMain(args, "number_of_score_combinations.tsv",
                  &NumCombinationsForFinalScore, DefaultComparator{},
                  param_names);
  return 0;
}
