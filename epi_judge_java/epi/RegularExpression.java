package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class RegularExpression {
  @EpiTest(testfile = "regular_expression.tsv")

  public static boolean isMatch(String regex, String s) {
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
