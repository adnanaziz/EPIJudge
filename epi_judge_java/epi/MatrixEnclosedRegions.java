package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

import java.util.List;

public class MatrixEnclosedRegions {

  public static void fillSurroundedRegions(List<List<Character>> board) {
    // Implement this placeholder.
    return;
  }

  @EpiTest(testfile = "matrix_enclosed_regions.tsv")
  public static List<List<Character>>
  fillSurroundedRegionsWrapper(List<List<Character>> board) {
    fillSurroundedRegions(board);
    return board;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
