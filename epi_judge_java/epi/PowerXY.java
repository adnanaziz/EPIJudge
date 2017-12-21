package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class PowerXY {
  @EpiTest(testfile = "power_x_y.tsv")
  public static double power(double x, int y) {
    // Implement this placeholder.
    return 0.0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
