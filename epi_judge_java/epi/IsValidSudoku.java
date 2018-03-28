package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class IsValidSudoku {
  @EpiTest(testfile = "is_valid_sudoku.tsv")

  // Check if a partially filled matrix has any conflicts.
  public static boolean isValidSudoku(List<List<Integer>> partialAssignment) {
    // Implement this placeholder.
    return true;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
