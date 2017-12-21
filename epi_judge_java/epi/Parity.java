package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class Parity {
  @EpiTest(testfile = "parity.tsv")
  public static short parity(long x) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
