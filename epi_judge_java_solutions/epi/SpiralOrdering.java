package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.List;

public class SpiralOrdering {
  @EpiTest(testDataFile = "spiral_ordering.tsv")

  public static List<Integer>
  matrixInSpiralOrder(List<List<Integer>> squareMatrix) {

    List<Integer> spiralOrdering = new ArrayList<>();
    for (int offset = 0; offset < Math.ceil(0.5 * squareMatrix.size());
         ++offset) {
      matrixLayerInClockwise(squareMatrix, offset, spiralOrdering);
    }
    return spiralOrdering;
  }

  private static void matrixLayerInClockwise(List<List<Integer>> squareMatrix,
                                             int offset,
                                             List<Integer> spiralOrdering) {
    if (offset == squareMatrix.size() - offset - 1) {
      // squareMatrix has odd dimension, and we are at its center.
      spiralOrdering.add(squareMatrix.get(offset).get(offset));
      return;
    }

    for (int j = offset; j < squareMatrix.size() - offset - 1; ++j) {
      spiralOrdering.add(squareMatrix.get(offset).get(j));
    }
    for (int i = offset; i < squareMatrix.size() - offset - 1; ++i) {
      spiralOrdering.add(
          squareMatrix.get(i).get(squareMatrix.size() - offset - 1));
    }
    for (int j = squareMatrix.size() - offset - 1; j > offset; --j) {
      spiralOrdering.add(
          squareMatrix.get(squareMatrix.size() - offset - 1).get(j));
    }
    for (int i = squareMatrix.size() - offset - 1; i > offset; --i) {
      spiralOrdering.add(squareMatrix.get(i).get(offset));
    }
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SpiralOrdering.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
