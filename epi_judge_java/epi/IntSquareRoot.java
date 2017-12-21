package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class IntSquareRoot {
  @EpiTest(testfile = "int_square_root.tsv")

  public static int squareRoot(int k) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
