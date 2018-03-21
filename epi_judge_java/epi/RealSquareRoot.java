package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class RealSquareRoot {
  @EpiTest(testfile = "real_square_root.tsv")

  public static double squareRoot(double x) {
    // Implement this placeholder.
    return 0.0;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
