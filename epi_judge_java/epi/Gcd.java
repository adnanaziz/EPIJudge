package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class Gcd {
  @EpiTest(testfile = "gcd.tsv")

  public static long GCD(long x, long y) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
