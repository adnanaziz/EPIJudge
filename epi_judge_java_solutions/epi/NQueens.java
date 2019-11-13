package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.GenericTest;
import epi.test_framework.LexicographicalListComparator;

import java.util.ArrayList;
import java.util.List;
import java.util.function.BiPredicate;

public class NQueens {
  @EpiTest(testDataFile = "n_queens.tsv")

  public static List<List<Integer>> nQueens(int n) {

    List<List<Integer>> result = new ArrayList<>();
    solveNQueens(n, 0, new ArrayList<Integer>(), result);
    return result;
  }

  private static void solveNQueens(int n, int row, List<Integer> colPlacement,
                                   List<List<Integer>> result) {
    if (row == n) {
      // All queens are legally placed.
      result.add(new ArrayList<>(colPlacement));
    } else {
      for (int col = 0; col < n; ++col) {
        colPlacement.add(col);
        if (isValid(colPlacement)) {
          solveNQueens(n, row + 1, colPlacement, result);
        }
        colPlacement.remove(colPlacement.size() - 1);
      }
    }
  }

  // Test if a newly placed queen will conflict any earlier queens
  // placed before.
  private static boolean isValid(List<Integer> colPlacement) {
    int rowID = colPlacement.size() - 1;
    for (int i = 0; i < rowID; ++i) {
      int diff = Math.abs(colPlacement.get(i) - colPlacement.get(rowID));
      if (diff == 0 || diff == rowID - i) {
        return false;
      }
    }
    return true;
  }

  @EpiTestComparator
  public static boolean comp(List<List<Integer>> expected,
                             List<List<Integer>> result) {
    if (result == null) {
      return false;
    }
    expected.sort(new LexicographicalListComparator<>());
    result.sort(new LexicographicalListComparator<>());
    return expected.equals(result);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "NQueens.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
