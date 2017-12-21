package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

import java.util.List;

public class BstFromSortedArray {
  @EpiTest(testfile = "bst_from_sorted_array.tsv")

  public static BstNode<Integer> buildMinHeightBSTFromSortedArray(List<Integer> A) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
