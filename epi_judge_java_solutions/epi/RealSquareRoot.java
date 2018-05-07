package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class RealSquareRoot {
  @EpiTest(testDataFile = "real_square_root.tsv")

  public static double squareRoot(double x) {

    // Decides the search range according to x's value relative to 1.0.
    double left, right;
    if (x < 1.0) {
      left = x;
      right = 1.0;
    } else { // x >= 1.0.
      left = 1.0;
      right = x;
    }

    // Keeps searching as long as left != right, within tolerance.
    while (compare(left, right) != Ordering.EQUAL) {
      double mid = left + 0.5 * (right - left);
      double midSquared = mid * mid;
      if (compare(midSquared, x) == Ordering.LARGER) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return left;
  }

  private enum Ordering { SMALLER, EQUAL, LARGER }

  private static Ordering compare(double a, double b) {
    final double EPSILON = 0.000001;
    // Uses normalization for precision problem.
    double diff = (a - b) / Math.max(Math.abs(a), Math.abs(b));
    return diff < -EPSILON
        ? Ordering.SMALLER
        : (diff > EPSILON ? Ordering.LARGER : Ordering.EQUAL);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "RealSquareRoot.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
