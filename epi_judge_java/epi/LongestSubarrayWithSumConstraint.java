package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class LongestSubarrayWithSumConstraint {
  @EpiTest(testfile = "longest_subarray_with_sum_constraint.tsv")

  public static int findLongestSubarrayLessEqualK(List<Integer> A, int k) {
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
