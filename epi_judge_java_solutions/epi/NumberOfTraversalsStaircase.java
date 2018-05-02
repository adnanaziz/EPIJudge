package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class NumberOfTraversalsStaircase {
  @EpiTest(testDataFile = "number_of_traversals_staircase.tsv")

  public static int numberOfWaysToTop(int top, int maximumStep) {

    return computeNumberOfWaysToH(top, maximumStep, new int[top + 1]);
  }

  private static int computeNumberOfWaysToH(int n, int maximumStep,
                                            int[] numberOfWaysToH) {
    if (n <= 1) {
      return 1;
    }
    if (numberOfWaysToH[n] == 0) {
      for (int i = 1; i <= maximumStep && n - i >= 0; ++i) {
        numberOfWaysToH[n] +=
            computeNumberOfWaysToH(n - i, maximumStep, numberOfWaysToH);
      }
    }
    return numberOfWaysToH[n];
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "NumberOfTraversalsStaircase.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
