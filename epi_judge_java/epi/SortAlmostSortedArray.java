package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

import java.util.Iterator;
import java.util.List;

public class SortAlmostSortedArray {

  public static List<Integer>
  sortApproximatelySortedData(Iterator<Integer> sequence, int k) {
    // Implement this placeholder.
    return null;
  }

  @EpiTest(testfile = "sort_almost_sorted_array.tsv")
  public static List<Integer>
  sortApproximatelySortedDataWrapper(List<Integer> sequence, int k) {
    return sortApproximatelySortedData(sequence.iterator(), k);
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
