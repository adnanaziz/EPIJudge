package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class ClosestIntSameWeight {
  @EpiTest(testfile = "closest_int_same_weight.tsv")
  public static long closestIntSameBitCount(long x) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
