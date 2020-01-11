package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
public class LongestSubarrayWithDistinctValues {
  @EpiTest(testDataFile = "longest_subarray_with_distinct_values.tsv")

  public static int longestSubarrayWithDistinctEntries(List<Integer> A) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "LongestSubarrayWithDistinctValues.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
