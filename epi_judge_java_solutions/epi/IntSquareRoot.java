package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class IntSquareRoot {
  @EpiTest(testDataFile = "int_square_root.tsv")

  public static int squareRoot(int k) {

    long left = 0, right = k;
    // Candidate interval [left, right] where everything before left has
    // square <= k, and everything after right has square > k.
    while (left <= right) {
      long mid = left + ((right - left) / 2);
      long midSquared = mid * mid;
      if (midSquared <= k) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return (int)left - 1;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "IntSquareRoot.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
