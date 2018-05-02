package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.Map;

public class RomanToInteger {
  @EpiTest(testDataFile = "roman_to_integer.tsv")

  public static int romanToInteger(String s) {

    Map<Character, Integer> T =
        Map.of('I', 1, 'V', 5, 'X', 10, 'L', 50, 'C', 100, 'D', 500, 'M', 1000);

    int sum = T.get(s.charAt(s.length() - 1));
    for (int i = s.length() - 2; i >= 0; --i) {
      if (T.get(s.charAt(i)) < T.get(s.charAt(i + 1))) {
        sum -= T.get(s.charAt(i));
      } else {
        sum += T.get(s.charAt(i));
      }
    }
    return sum;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "RomanToInteger.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
