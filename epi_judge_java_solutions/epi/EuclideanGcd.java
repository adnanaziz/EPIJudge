package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class EuclideanGcd {
  @EpiTest(testDataFile = "gcd.tsv")

  public static long GCD(long x, long y) {

    return y == 0 ? x : GCD(y, x % y);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "EuclideanGcd.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
