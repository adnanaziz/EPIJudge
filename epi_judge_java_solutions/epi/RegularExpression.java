package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class RegularExpression {
  @EpiTest(testDataFile = "regular_expression.tsv")

  public static boolean isMatch(String regex, String s) {

    // Case (2.): regex starts with '^'.
    if (regex.charAt(0) == '^') {
      return isMatchHere(regex.substring(1), s);
    }

    for (int i = 0; i <= s.length(); ++i) {
      if (isMatchHere(regex, s.substring(i))) {
        return true;
      }
    }
    return false;
  }

  private static boolean isMatchHere(String regex, String s) {
    if (regex.isEmpty()) {
      // Case (1.): Empty regex matches all strings.
      return true;
    }

    if ("$".equals(regex)) {
      // Case (2): Reach the end of regex, and last char is '$'.
      return s.isEmpty();
    }

    if (regex.length() >= 2 && regex.charAt(1) == '*') {
      // Case (3.): A '*' match.
      // Iterate through s, checking '*' condition, if '*' condition holds,
      // performs the remaining checks.
      for (int i = 0; i < s.length() && (regex.charAt(0) == '.' ||
                                         regex.charAt(0) == s.charAt(i));
           ++i) {
        if (isMatchHere(regex.substring(2), s.substring(i + 1))) {
          return true;
        }
      }
      // See '*' matches zero character in s.
      return isMatchHere(regex.substring(2), s);
    }

    // Case (4.): regex begins with single character match.
    return !s.isEmpty() &&
        (regex.charAt(0) == '.' || regex.charAt(0) == s.charAt(0)) &&
        isMatchHere(regex.substring(1), s.substring(1));
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "RegularExpression.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
