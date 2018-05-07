package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class Parity {

  @EpiTest(testDataFile = "parity.tsv")
  public static short parity(long x) {

    short result = 0;
    while (x != 0) {
      result ^= (x & 1);
      x >>>= 1;
    }
    return result;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "Parity.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
