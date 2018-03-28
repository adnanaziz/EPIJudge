package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class MatrixRotation {

  public static void rotateMatrix(List<List<Integer>> squareMatrix) {
    // Implement this placeholder.
    return;
  }

  @EpiTest(testfile = "matrix_rotation.tsv")
  public static List<List<Integer>>
  rotateMatrixWrapper(List<List<Integer>> squareMatrix) {
    rotateMatrix(squareMatrix);
    return squareMatrix;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
