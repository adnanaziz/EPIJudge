package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class EvaluateRpn {
  @EpiTest(testfile = "evaluate_rpn.tsv")

  public static int eval(String expression) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
