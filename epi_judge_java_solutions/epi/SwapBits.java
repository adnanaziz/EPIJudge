package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class SwapBits {

  @EpiTest(testDataFile = "swap_bits.tsv")
  public static long swapBits(long x, int i, int j) {

    // Extract the i-th and j-th bits, and see if they differ.
    if (((x >>> i) & 1) != ((x >>> j) & 1)) {
      // i-th and j-th bits differ. We will swap them by flipping their values.
      // Select the bits to flip with bitMask. Since x^1 = 0 when x = 1 and 1
      // when x = 0, we can perform the flip XOR.
      long bitMask = (1L << i) | (1L << j);
      x ^= bitMask;
    }
    return x;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SwapBits.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
