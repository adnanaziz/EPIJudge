package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class ReverseDigits {

  @EpiTest(testDataFile = "reverse_digits.tsv")
  public static long reverse(int x) {

    long result = 0;
    long xRemaining = Math.abs(x);
    while (xRemaining != 0) {
      result = result * 10 + xRemaining % 10;
      xRemaining /= 10;
    }
    return x < 0 ? -result : result;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "ReverseDigits.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
