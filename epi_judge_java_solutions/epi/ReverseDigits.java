package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class ReverseDigits {

  @EpiTest(testDataFile = "reverse_digits.tsv")
  public static long reverse(int x) {

    long result = 0;
    while (x != 0) {
      // If x is an negative, x % 10 is the negative of least significant digit.
      // For example, -256 % 10 = -6.
      result = result * 10 + (x % 10);
      x /= 10;
    }
    return result;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "ReverseDigits.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
