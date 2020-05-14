package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
public class MaxSumSubarray {
  @EpiTest(testDataFile = "max_sum_subarray.tsv")

  public static int findMaximumSubarray(List<Integer> A) {
    // TODO - you fill in here.
    return -1;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MaxSumSubarray.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
