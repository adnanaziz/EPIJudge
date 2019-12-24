package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class SearchRowColSortedMatrix {
  
  @EpiTest(testDataFile = "search_row_col_sorted_matrix.tsv")
  public static boolean matrixSearch(List<List<Integer>> A, int x) {
    int rowSize = A.get(0).size();
    int colSize = A.size();
    for (int i = 0; i < Math.min(rowSize, colSize); i++) {
      if (matrixBinarySearch(A, i, false, x) || matrixBinarySearch(A, i, true, x)) {
        return true;
      }
    }
    return false;
  }

  private static boolean matrixBinarySearch(List<List<Integer>> A, int index, boolean colSearch, int target) {
    int lo = index, hi = colSearch ? A.size() - 1: A.get(0).size() - 1;
    while (lo < hi) {
      int mid = lo + (hi-lo)/2;
      if (colSearch) {
        if (A.get(mid).get(index) >= target) {
          hi = mid;
        } else {
          lo = mid + 1;
        }
      } else {
        if (A.get(index).get(mid) >= target) {
          hi = mid;
        } else {
          lo = mid + 1;
        }
      }
    }
    return colSearch && A.get(lo).get(index) == target || !colSearch && A.get(index).get(lo) == target;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SearchRowColSortedMatrix.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
