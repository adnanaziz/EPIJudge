package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class CountBits {
  @EpiTest(testfile = "count_bits.tsv")

  public static short countBits(int x) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
