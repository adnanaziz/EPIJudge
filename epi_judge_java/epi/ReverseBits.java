package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class ReverseBits {

  @EpiTest(testfile = "reverse_bits.tsv")
  public static long reverseBits(long x) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
