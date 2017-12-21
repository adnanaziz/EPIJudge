package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.GenericTestHandler;

import java.util.Collections;
import java.util.List;
import java.util.function.BiPredicate;

public class KLargestValuesInBst {
  @EpiTest(testfile = "k_largest_values_in_bst.tsv")

  public static List<Integer> findKLargestInBst(BstNode<Integer> tree, int k) {
    // Implement this placeholder.
    return null;
  }

  @EpiTestComparator
  public static BiPredicate<List<Integer>, List<Integer>> comp = (a, b) -> {
    Collections.sort(a);
    Collections.sort(b);
    return a.equals(b);
  };

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
