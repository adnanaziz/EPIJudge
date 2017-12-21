package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Objects;
import java.util.Set;

public class SudokuSolve {
  public static boolean solveSudoku(List<List<Integer>> partialAssignment) {
    // Implement this placeholder.
    return true;
  }

  @EpiTest(testfile = "sudoku_solve.tsv")
  public static void solveSudokuWrapper(TestTimer timer, List<List<Integer>> board)
      throws TestFailureException {
    List<List<Integer>> solved = new ArrayList<>();
    for (List<Integer> row : board) {
      List<Integer> copy = new ArrayList<>();
      copy.addAll(row);
      solved.add(copy);
    }

    timer.start();
    solveSudoku(solved);
    timer.stop();

    if (board.size() != solved.size()) {
      throw new TestFailureException("Initial cell assignment has been changed");
    }

    for (int i = 0; i < board.size(); i++) {
      List<Integer> br = board.get(i);
      List<Integer> sr = solved.get(i);
      if (br.size() != sr.size()) {
        throw new TestFailureException("Initial cell assignment has been changed");
      }
      for (int j = 0; j < br.size(); j++)
        if (br.get(j) != 0 && !Objects.equals(br.get(j), sr.get(j)))
          throw new TestFailureException("Initial cell assignment has been changed");
    }

    int blockSize = (int) Math.sqrt(solved.size());
    for (int i = 0; i < solved.size(); i++) {
      assertUniqueSeq(solved.get(i));
      assertUniqueSeq(gatherColumn(solved, i));
      assertUniqueSeq(gatherSquareBlock(solved, blockSize, i));
    }
  }

  private static void assertUniqueSeq(List<Integer> seq) throws TestFailureException {
    Set<Integer> seen = new HashSet<>();
    for (Integer x : seq) {
      if (x == 0) {
        throw new TestFailureException("Cell left uninitialized");
      }
      if (x < 0 || x > seq.size()) {
        throw new TestFailureException("Cell value out of range");
      }
      if (seen.contains(x)) {
        throw new TestFailureException("Duplicate value in section");
      }
      seen.add(x);
    }
  }

  private static List<Integer> gatherColumn(List<List<Integer>> data, int i) {
    List<Integer> result = new ArrayList<>();
    for (List<Integer> row : data) {
      result.add(row.get(i));
    }
    return result;
  }

  private static List<Integer> gatherSquareBlock(List<List<Integer>> data, int blockSize, int n) {
    List<Integer> result = new ArrayList<>();
    int block_x = n % blockSize;
    int block_y = n / blockSize;
    for (int i = block_x * blockSize; i < (block_x + 1) * blockSize; i++) {
      for (int j = block_y * blockSize; j < (block_y + 1) * blockSize; j++) {
        result.add(data.get(i).get(j));
      }
    }

    return result;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
