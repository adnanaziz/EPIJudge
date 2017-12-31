package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

import java.util.List;

public class SpiralOrderingSegments {
  @EpiTest(testfile = "spiral_ordering_segments.tsv")

  public static List<Integer>
  matrixInSpiralOrder(List<List<Integer>> squareMatrix) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
