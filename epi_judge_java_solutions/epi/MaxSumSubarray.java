package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class MaxSumSubarray {
  @EpiTest(testDataFile = "max_sum_subarray.tsv")

  public static int findMaximumSubarray(List<Integer> A) {

    int maxSeen = 0, maxEnd = 0;
    for (int a : A) {
      maxEnd = Math.max(a, a + maxEnd);
      maxSeen = Math.max(maxSeen, maxEnd);
    }
    return maxSeen;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MaxSumSubarray.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
