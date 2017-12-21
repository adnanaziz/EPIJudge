package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class RegularExpression {
  @EpiTest(testfile = "regular_expression.tsv")

  public static boolean isMatch(String regex, String s) {
    // Implement this placeholder.
    return true;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
