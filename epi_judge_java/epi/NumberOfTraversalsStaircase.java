package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class NumberOfTraversalsStaircase {
  @EpiTest(testfile = "number_of_traversals_staircase.tsv")

  public static int numberOfWaysToTop(int top, int maximumStep) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
