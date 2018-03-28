package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class IsNumberPalindromic {
  @EpiTest(testfile = "is_number_palindromic.tsv")
  public static boolean isPalindromeNumber(int x) {
    // Implement this placeholder.
    return true;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
