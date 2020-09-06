package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailure;

import java.util.List;
public class LongestIncreasingSubarray {

  // Represent subarray by starting and ending indices, inclusive.
  private static class Subarray {
    public Integer start;
    public Integer end;

    public Subarray(Integer start, Integer end) {
      this.start = start;
      this.end = end;
    }
  }

  public static Subarray findLongestIncreasingSubarray(List<Integer> A) {
    // TODO - you fill in here.
    return new Subarray(0, 0);
  }

  @EpiTest(testDataFile = "longest_increasing_subarray.tsv")
  public static int findLongestIncreasingSubarrayWrapper(List<Integer> A)
      throws Exception {
    Subarray result = findLongestIncreasingSubarray(A);

    if (result.start < 0 || result.start >= A.size() ||
      result.end < 0 || result.end >= A.size() ||
      result.start > result.end)
      throw new TestFailure("Index out of range");

    for (int i = result.start + 1; i < result.end; ++i) {
      if (A.get(i) <= A.get(i - 1)) {
      throw new TestFailure()
          .withMismatchInfo(
              i, String.format("A[%d] < A[%d]", i - 1, i),
              String.format("%d >= %d", A.get(i - 1), A.get(i)));
      }
    }

    return result.end - result.start + 1;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "LongestIncreasingSubarray.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
