package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class IsStringPalindromicPunctuation {
  @EpiTest(testDataFile = "is_string_palindromic_punctuation.tsv")

  public static boolean isPalindrome(String s) {

    // i moves forward, and j moves backward.
    int i = 0, j = s.length() - 1;
    while (i < j) {
      // i and j both skip non-alphanumeric characters.
      while (!Character.isLetterOrDigit(s.charAt(i)) && i < j) {
        ++i;
      }
      while (!Character.isLetterOrDigit(s.charAt(j)) && i < j) {
        --j;
      }
      if (Character.toLowerCase(s.charAt(i++)) !=
          Character.toLowerCase(s.charAt(j--))) {
        return false;
      }
    }
    return true;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "IsStringPalindromicPunctuation.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
