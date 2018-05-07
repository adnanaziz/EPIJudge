package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class MaxSumSubarray {
  @EpiTest(testDataFile = "max_sum_subarray.tsv")

  public static int findMaximumSubarray(List<Integer> A) {

    int minSum = 0, runningSum = 0, maxSum = 0;
    for (int i = 0; i < A.size(); ++i) {
      runningSum += A.get(i);
      if (runningSum < minSum) {
        minSum = runningSum;
      }
      if (runningSum - minSum > maxSum) {
        maxSum = runningSum - minSum;
      }
    }
    return maxSum;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MaxSumSubarray.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
