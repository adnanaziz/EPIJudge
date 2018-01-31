package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;

public class StringIntegerInterconversion {

  public static String intToString(int x) {
    // Implement this placeholder.
    return "";
  }

  public static int stringToInt(String s) {
    // Implement this placeholder.
    return 0;
  }

  @EpiTest(testfile = "string_integer_interconversion.tsv")
  public static void wrapper(int x, String s) throws TestFailureException {
    if (!intToString(x).equals(s)) {
      throw new TestFailureException("Int to string conversion failed");
    }
    if (stringToInt(s) != x) {
      throw new TestFailureException("String to int conversion failed");
    }
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
