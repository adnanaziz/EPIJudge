package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class LongestContainedInterval {
  @EpiTest(testDataFile = "longest_contained_interval.tsv")

  public static int longestContainedRange(List<Integer> A) {

    // unprocessedEntries records the existence of each entry in A.
    Set<Integer> unprocessedEntries = new HashSet<>(A);

    int maxIntervalSize = 0;
    while (!unprocessedEntries.isEmpty()) {
      int a = unprocessedEntries.iterator().next();
      unprocessedEntries.remove(a);

      // Finds the lower bound of the largest range containing a.
      int lowerBound = a - 1;
      while (unprocessedEntries.contains(lowerBound)) {
        unprocessedEntries.remove(lowerBound);
        --lowerBound;
      }

      // Finds the upper bound of the largest range containing a.
      int upperBound = a + 1;
      while (unprocessedEntries.contains(upperBound)) {
        unprocessedEntries.remove(upperBound);
        ++upperBound;
      }

      maxIntervalSize = Math.max(upperBound - lowerBound - 1, maxIntervalSize);
    }
    return maxIntervalSize;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "LongestContainedInterval.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
