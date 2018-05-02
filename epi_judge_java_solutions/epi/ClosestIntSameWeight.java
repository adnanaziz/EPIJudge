package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class ClosestIntSameWeight {

  @EpiTest(testDataFile = "closest_int_same_weight.tsv")
  public static long closestIntSameBitCount(long x) {

    final int NUM_UNSIGNED_BITS = 63;
    // x is assumed to be non-negative so we know the leading bit is 0. We
    // restrict to our attention to 63 LSBs.
    for (int i = 0; i < NUM_UNSIGNED_BITS - 1; ++i) {
      if ((((x >>> i) & 1) != ((x >>> (i + 1)) & 1))) {
        x ^= (1L << i) | (1L << (i + 1)); // Swaps bit-i and bit-(i + 1).
        return x;
      }
    }

    // Throw error if all bits of x are 0 or 1.
    throw new IllegalArgumentException("All bits are 0 or 1");
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "ClosestIntSameWeight.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
