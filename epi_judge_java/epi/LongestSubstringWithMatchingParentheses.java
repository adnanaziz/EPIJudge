package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
public class LongestSubstringWithMatchingParentheses {
  @EpiTest(testDataFile = "longest_substring_with_matching_parentheses.tsv")

  public static int longestMatchingParentheses(String s) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, "LongestSubstringWithMatchingParentheses.java",
                        new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
