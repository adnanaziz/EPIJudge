package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class NumberOfTraversalsMatrix {
  @EpiTest(testfile = "number_of_traversals_matrix.tsv")

  public static int numberOfWays(int n, int m) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
