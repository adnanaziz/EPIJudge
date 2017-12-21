package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class SwapBits {
  @EpiTest(testfile = "swap_bits.tsv")
  public static long swapBits(long x, int i, int j) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
