package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class MaxSubmatrix {

  private static class MaxHW {
    public int h, w;

    public MaxHW(int h, int w) {
      this.h = h;
      this.w = w;
    }
  }

  @EpiTest(testDataFile = "max_submatrix.tsv")

  public static int maxRectangleSubmatrix(List<List<Boolean>> A) {

    // DP table stores (h, w) for each (i, j).
    MaxHW[][] table = new MaxHW[A.size()][A.get(0).size()];

    for (int i = A.size() - 1; i >= 0; --i) {
      for (int j = A.get(i).size() - 1; j >= 0; --j) {
        // Find the largest h such that (i, j) to (i + h - 1, j) are feasible.
        // Find the largest w such that (i, j) to (i, j + w - 1) are feasible.
        table[i][j] =
            A.get(i).get(j)
                ? new MaxHW(i + 1 < A.size() ? table[i + 1][j].h + 1 : 1,
                            j + 1 < A.get(i).size() ? table[i][j + 1].w + 1 : 1)
                : new MaxHW(0, 0);
      }
    }

    int maxRectangleArea = 0;
    for (int i = 0; i < A.size(); ++i) {
      for (int j = 0; j < A.get(i).size(); ++j) {
        // Process (i, j) if it is feasible and is possible to update
        // maxRectangleArea.
        if (A.get(i).get(j) &&
            table[i][j].w * table[i][j].h > maxRectangleArea) {
          int minWidth = Integer.MAX_VALUE;
          for (int a = 0; a < table[i][j].h; ++a) {
            minWidth = Math.min(minWidth, table[i + a][j].w);
            maxRectangleArea = Math.max(maxRectangleArea, minWidth * (a + 1));
          }
        }
      }
    }
    return maxRectangleArea;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MaxSubmatrix.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
