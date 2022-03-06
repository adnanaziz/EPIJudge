#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int CalculateFinalCombination(int final_score, const vector<int>& individual_play_scores, 
                              vector<vector<int>>& num_combination){
    for (int i = 0; i < individual_play_scores.size(); i++) {
        num_combination[i][0] = 1;
        for (int j = 1; j <= final_score; j++) {
            int without_own = i >= 1 ? num_combination[i - 1][j]:0;
            int with_own = j >= individual_play_scores[i] ? num_combination[i][j - individual_play_scores[i]] : 0;
            num_combination[i][j] = without_own + with_own;
        }
    }
    return num_combination.back().back();
}

int NumCombinationsForFinalScore(int final_score,
                                 const vector<int>& individual_play_scores) {
    vector<vector<int>> num_combination(individual_play_scores.size(), vector<int>(final_score+1, 0));
    return CalculateFinalCombination(final_score, individual_play_scores,num_combination);
}


int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"final_score", "individual_play_scores"};
  return GenericTestMain(args, "number_of_score_combinations.cc",
                         "number_of_score_combinations.tsv",
                         &NumCombinationsForFinalScore, DefaultComparator{},
                         param_names);
}
