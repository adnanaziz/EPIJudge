package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

import java.util.List;

public class IntersectSortedArrays {
  @EpiTest(testfile = "intersect_sorted_arrays.tsv")

  public static List<Integer> intersectTwoSortedArrays(List<Integer> A,
                                                       List<Integer> B) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
