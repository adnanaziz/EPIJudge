package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MaxSquareSubmatrix {

  public static class MaxHW {
    public int h, w;

    public MaxHW(int h, int w) {
      this.h = h;
      this.w = w;
    }
  }

  @EpiTest(testDataFile = "max_square_submatrix.tsv")

  public static int maxSquareSubmatrix(List<List<Boolean>> A) {

    // DP table stores (h, w) for each (i, j).
    List<List<MaxHW>> table = new ArrayList<>(A.size());
    for (List<Boolean> a : A) {
      table.add(
          new ArrayList<>(Collections.nCopies(a.size(), new MaxHW(0, 0))));
    }

    for (int i = A.size() - 1; i >= 0; --i) {
      for (int j = A.get(i).size() - 1; j >= 0; --j) {
        // Find the largest h such that (i, j) to (i + h - 1, j) are feasible.
        // Find the largest w such that (i, j) to (i, j + w - 1) are feasible.
        table.get(i).set(
            j, A.get(i).get(j)
                   ? new MaxHW(
                         i + 1 < A.size() ? table.get(i + 1).get(j).h + 1 : 1,
                         j + 1 < A.get(i).size() ? table.get(i).get(j + 1).w + 1
                                                 : 1)
                   : new MaxHW(0, 0));
      }
    }

    // A table stores the length of the largest square for each (i, j).
    List<List<Integer>> s = new ArrayList<>(A.size());
    for (List<Boolean> a : A) {
      s.add(new ArrayList<>(Collections.nCopies(a.size(), 0)));
    }
    int maxSquareArea = 0;
    for (int i = A.size() - 1; i >= 0; --i) {
      for (int j = A.get(i).size() - 1; j >= 0; --j) {
        int side = Math.min(table.get(i).get(j).h, table.get(i).get(j).w);
        if (A.get(i).get(j)) {
          // Get the length of largest square with bottom-left corner (i, j).
          if (i + 1 < A.size() && j + 1 < A.get(i + 1).size()) {
            side = Math.min(s.get(i + 1).get(j + 1) + 1, side);
          }
          s.get(i).set(j, side);
          maxSquareArea = Math.max(maxSquareArea, side * side);
        }
      }
    }
    return maxSquareArea;
  }

  public static int maxSquareSubmatrixSpaceEfficient(List<List<Boolean>> A) {
    List<Integer> pre =
        new ArrayList<>(Collections.nCopies(A.get(0).size(), 0));
    int maxSide = 0;
    for (List<Boolean> row : A) {
      List<Integer> curr = new ArrayList<>(A.get(0).size());
      for (Boolean cell : row) {
        curr.add(cell ? 1 : 0);
      }
      for (int j = 1; j < curr.size(); ++j) {
        curr.set(j,
                 curr.get(j) * (Math.min(Math.min(pre.get(j - 1), pre.get(j)),
                                         curr.get(j - 1)) +
                                1));
      }
      maxSide = Math.max(maxSide, Collections.max(curr));
      pre = curr;
    }
    return maxSide * maxSide;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MaxSquareSubmatrix.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
