package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class IsStringPermutableToPalindrome {
  @EpiTest(testfile = "can_string_be_palindrome.tsv")

  public static boolean canFormPalindrome(String s) {
    // Implement this placeholder.
    return true;
  }

  public static void main(String[] args) {
    GenericTest.runFromAnnotations(
        args, new Object() {}.getClass().getEnclosingClass());
  }
}
