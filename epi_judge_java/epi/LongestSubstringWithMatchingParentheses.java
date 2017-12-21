package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class LongestSubstringWithMatchingParentheses {
  @EpiTest(testfile = "longest_substring_with_matching_parentheses.tsv")

  public static int longestMatchingParentheses(String s) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
