package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.GenericTestHandler;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.function.BiPredicate;

public class KLargestInHeap {
  @EpiTest(testfile = "k_largest_in_heap.tsv")

  public static List<Integer> kLargestInBinaryHeap(List<Integer> A, int k) {
    // Implement this placeholder.
    return null;
  }

  @EpiTestComparator
  @SuppressWarnings("unchecked")
  public static BiPredicate<Object, Object> comp = (Object a, Object b) -> {
    List<Integer> la = (List<Integer>) a;
    List<Integer> lb = (List<Integer>) b;
    Collections.sort(la);
    Collections.sort(lb);
    return la.equals(lb);
  };

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
