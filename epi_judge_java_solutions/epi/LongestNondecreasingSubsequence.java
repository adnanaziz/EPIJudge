package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class LongestNondecreasingSubsequence {
  @EpiTest(testDataFile = "longest_nondecreasing_subsequence.tsv")

  public static int longestNondecreasingSubsequenceLength(List<Integer> A) {

    // maxLength[i] holds the length of the longest nondecreasing subsequence of
    // A.subList(0, i + 1).
    Integer[] maxLength = new Integer[A.size()];
    Arrays.fill(maxLength, 1);
    for (int i = 1; i < A.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (A.get(i) >= A.get(j)) {
          maxLength[i] = Math.max(maxLength[i], maxLength[j] + 1);
        }
      }
    }
    return Collections.max(List.of(maxLength));
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "LongestNondecreasingSubsequence.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
