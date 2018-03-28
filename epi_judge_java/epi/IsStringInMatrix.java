package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class IsStringInMatrix {

  @EpiTest(testfile = "is_string_in_matrix.tsv")
  public static boolean isPatternContainedInGrid(List<List<Integer>> grid,
                                                 List<Integer> pattern) {
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
