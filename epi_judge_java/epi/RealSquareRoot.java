package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class RealSquareRoot {
  @EpiTest(testfile = "real_square_root.tsv")

  public static double squareRoot(double x) {
    // Implement this placeholder.
    return 0.0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
