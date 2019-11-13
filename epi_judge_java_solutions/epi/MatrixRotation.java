package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class MatrixRotation {

  public static void rotateMatrix(List<List<Integer>> squareMatrix) {

    final int matrixSize = squareMatrix.size() - 1;
    for (int i = 0; i < (squareMatrix.size() / 2); ++i) {
      for (int j = i; j < matrixSize - i; ++j) {
        // Perform a 4-way exchange.
        int temp1 = squareMatrix.get(matrixSize - j).get(i);
        int temp2 = squareMatrix.get(matrixSize - i).get(matrixSize - j);
        int temp3 = squareMatrix.get(j).get(matrixSize - i);
        int temp4 = squareMatrix.get(i).get(j);
        squareMatrix.get(i).set(j, temp1);
        squareMatrix.get(matrixSize - j).set(i, temp2);
        squareMatrix.get(matrixSize - i).set(matrixSize - j, temp3);
        squareMatrix.get(j).set(matrixSize - i, temp4);
      }
    }
  }

  @EpiTest(testDataFile = "matrix_rotation.tsv")
  public static List<List<Integer>>
  rotateMatrixWrapper(List<List<Integer>> squareMatrix) {
    rotateMatrix(squareMatrix);
    return squareMatrix;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MatrixRotation.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
