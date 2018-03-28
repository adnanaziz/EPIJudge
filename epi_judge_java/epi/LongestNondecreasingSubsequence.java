package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class LongestNondecreasingSubsequence {
  @EpiTest(testfile = "longest_nondecreasing_subsequence.tsv")

  public static int longestNondecreasingSubsequenceLength(List<Integer> A) {
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
