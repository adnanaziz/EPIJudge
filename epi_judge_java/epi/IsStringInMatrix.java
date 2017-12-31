package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

import java.util.List;

public class IsStringInMatrix {

  @EpiTest(testfile = "is_string_in_matrix.tsv")
  public static boolean isPatternContainedInGrid(List<List<Integer>> grid,
                                                 List<Integer> pattern) {
    // Implement this placeholder.
    return true;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
