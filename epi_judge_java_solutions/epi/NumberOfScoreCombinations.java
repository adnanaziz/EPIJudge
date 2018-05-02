package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class NumberOfScoreCombinations {
  @EpiTest(testDataFile = "number_of_score_combinations.tsv")

  public static int
  numCombinationsForFinalScore(int finalScore,
                               List<Integer> individualPlayScores) {

    int[][] numCombinationsForScore =
        new int[individualPlayScores.size()][finalScore + 1];
    for (int i = 0; i < individualPlayScores.size(); ++i) {
      numCombinationsForScore[i][0] = 1; // One way to reach 0.
      for (int j = 1; j <= finalScore; ++j) {
        int withoutThisPlay =
            i - 1 >= 0 ? numCombinationsForScore[i - 1][j] : 0;
        int withThisPlay =
            j >= individualPlayScores.get(i)
                ? numCombinationsForScore[i][j - individualPlayScores.get(i)]
                : 0;
        numCombinationsForScore[i][j] = withoutThisPlay + withThisPlay;
      }
    }
    return numCombinationsForScore[individualPlayScores.size() - 1][finalScore];
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "NumberOfScoreCombinations.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
