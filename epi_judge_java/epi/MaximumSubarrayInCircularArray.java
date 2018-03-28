package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class MaximumSubarrayInCircularArray {
  @EpiTest(testfile = "maximum_subarray_in_circular_array.tsv")

  public static int maxSubarraySumInCircular(List<Integer> A) {
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
