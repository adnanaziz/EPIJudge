package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class RomanToInteger {
  @EpiTest(testfile = "roman_to_integer.tsv")

  public static int romanToInteger(String s) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
