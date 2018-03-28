package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class ReverseDigits {
  @EpiTest(testfile = "reverse_digits.tsv")
  public static long reverse(int x) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
