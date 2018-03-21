package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class SnakeString {
  @EpiTest(testfile = "snake_string.tsv")

  public static String snakeString(String s) {
    // Implement this placeholder.
    return "";
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
