package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class MaxSafeHeight {
  @EpiTest(testfile = "max_safe_height.tsv")

  public static int getHeight(int cases, int drops) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
