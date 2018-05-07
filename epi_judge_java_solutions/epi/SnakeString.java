package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class SnakeString {
  @EpiTest(testDataFile = "snake_string.tsv")

  public static String snakeString(String s) {

    StringBuilder result = new StringBuilder();
    // Outputs the first row, i.e., s[1], s[5], s[9], ...
    for (int i = 1; i < s.length(); i += 4) {
      result.append(s.charAt(i));
    }
    // Outputs the second row, i.e., s[0], s[2], s[4], ...
    for (int i = 0; i < s.length(); i += 2) {
      result.append(s.charAt(i));
    }
    // Outputs the third row, i.e., s[3], s[7], s[11], ...
    for (int i = 3; i < s.length(); i += 4) {
      result.append(s.charAt(i));
    }
    return result.toString();
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SnakeString.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
