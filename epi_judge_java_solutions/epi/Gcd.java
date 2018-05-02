package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class Gcd {
  @EpiTest(testDataFile = "gcd.tsv")

  public static long GCD(long x, long y) {

    if (x > y) {
      return GCD(y, x);
    } else if (x == 0) {
      return y;
    } else if ((x & 1) == 0 && (y & 1) == 0) { // x and y are even.
      return GCD(x >>> 1, y >>> 1) << 1;
    } else if ((x & 1) == 0 && (y & 1) != 0) { // x is even, y is odd.
      return GCD(x >>> 1, y);
    } else if ((x & 1) != 0 && (y & 1) == 0) { // x is odd, y is even.
      return GCD(x, y >>> 1);
    }
    return GCD(x, y - x); // Both x and y are odd.
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "Gcd.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
