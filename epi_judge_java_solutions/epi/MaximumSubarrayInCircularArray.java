package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.IntStream;

public class MaximumSubarrayInCircularArray {
  @EpiTest(testDataFile = "maximum_subarray_in_circular_array.tsv")

  public static int maxSubarraySumInCircular(List<Integer> A) {

    return Math.max(findMaxSubarray(A), findCircularMaxSubarray(A));
  }

  // Calculates the non-circular solution.
  private static int findMaxSubarray(List<Integer> A) {
    int maximumTill = 0, maximum = 0;
    for (Integer a : A) {
      maximumTill = Math.max(a, a + maximumTill);
      maximum = Math.max(maximum, maximumTill);
    }
    return maximum;
  }

  // Calculates the solution which is circular.
  private static int findCircularMaxSubarray(List<Integer> A) {
    // Maximum subarray sum starts at index 0 and ends at or before index i.
    List<Integer> maximumBegin = computeRunningMaximum(A);

    // Maximum subarray sum starts at index i + 1 and ends at the last element.
    Collections.reverse(A);
    List<Integer> maximumEnd = computeRunningMaximum(A);
    maximumEnd.remove(maximumEnd.size() - 1);
    Collections.reverse(maximumEnd);
    maximumEnd.add(0);

    // Calculates the maximum subarray which is circular.
    return IntStream.range(0, A.size())
        .mapToObj(i -> maximumBegin.get(i) + maximumEnd.get(i))
        .max(Integer::compare)
        .orElse(0);
  }

  private static List<Integer> computeRunningMaximum(List<Integer> A) {
    List<Integer> runningMaximum = new ArrayList<>();
    int sum = A.get(0);
    runningMaximum.add(sum);
    for (int i = 1; i < A.size(); ++i) {
      sum += A.get(i);
      runningMaximum.add(
          Math.max(runningMaximum.get(runningMaximum.size() - 1), sum));
    }
    return runningMaximum;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MaximumSubarrayInCircularArray.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
