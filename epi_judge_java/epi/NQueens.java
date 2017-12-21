package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.LexicographicalListComparator;
import epi.test_framework.GenericTestHandler;

import java.util.List;
import java.util.function.BiPredicate;

public class NQueens {
  @EpiTest(testfile = "n_queens.tsv")

  public static List<List<Integer>> nQueens(int n) {
    // Implement this placeholder.
    return null;
  }

  @EpiTestComparator
  public static BiPredicate<List<List<Integer>>, List<List<Integer>>> comp = (a, b) -> {
    a.sort(new LexicographicalListComparator<>());
    b.sort(new LexicographicalListComparator<>());
    return a.equals(b);
  };

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
