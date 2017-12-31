package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

import java.util.List;

public class MaxSubmatrix {

  @EpiTest(testfile = "max_submatrix.tsv")

  public static int maxRectangleSubmatrix(List<List<Boolean>> A) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
