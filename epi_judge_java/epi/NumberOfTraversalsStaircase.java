package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class NumberOfTraversalsStaircase {
  @EpiTest(testfile = "number_of_traversals_staircase.tsv")

  public static int numberOfWaysToTop(int top, int maximumStep) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
