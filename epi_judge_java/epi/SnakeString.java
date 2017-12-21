package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class SnakeString {
  @EpiTest(testfile = "snake_string.tsv")

  public static String snakeString(String s) {
    // Implement this placeholder.
    return "";
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
