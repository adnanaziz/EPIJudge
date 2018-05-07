package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LongestSubarrayWithDistinctValues {
  @EpiTest(testDataFile = "longest_subarray_with_distinct_values.tsv")

  public static int longestSubarrayWithDistinctEntries(List<Integer> A) {

    // Records the most recent occurrences of each entry.
    Map<Integer, Integer> mostRecentOccurrence = new HashMap<>();
    int longestDupFreeSubarrayStartIdx = 0, result = 0;
    for (int i = 0; i < A.size(); ++i) {
      Integer dupIdx = mostRecentOccurrence.put(A.get(i), i);
      // A.get(i) appeared before. Did it appear in the longest current
      // subarray?
      if (dupIdx != null) {
        if (dupIdx >= longestDupFreeSubarrayStartIdx) {
          result = Math.max(result, i - longestDupFreeSubarrayStartIdx);
          longestDupFreeSubarrayStartIdx = dupIdx + 1;
        }
      }
    }
    return Math.max(result, A.size() - longestDupFreeSubarrayStartIdx);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "LongestSubarrayWithDistinctValues.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
