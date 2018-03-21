package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class IsValidParenthesization {
  @EpiTest(testfile = "is_valid_parenthesization.tsv")

  public static boolean isWellFormed(String s) {
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
