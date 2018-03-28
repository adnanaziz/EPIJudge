package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class LongestSubstringWithMatchingParentheses {
  @EpiTest(testfile = "longest_substring_with_matching_parentheses.tsv")

  public static int longestMatchingParentheses(String s) {
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
