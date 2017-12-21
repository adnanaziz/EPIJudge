package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.LexicographicalListComparator;
import epi.test_framework.GenericTestHandler;

import java.util.Collections;
import java.util.List;
import java.util.function.BiPredicate;

public class Combinations {
  @EpiTest(testfile = "combinations.tsv")

  public static List<List<Integer>> combinations(int n, int k) {
    // Implement this placeholder.
    return null;
  }

  @EpiTestComparator
  @SuppressWarnings("unchecked")
  public static BiPredicate<Object, Object> comp = (Object o1, Object o2) -> {
    List<List<Integer>> la = (List<List<Integer>>) o1;
    List<List<Integer>> lb = (List<List<Integer>>) o2;
    for (List<Integer> l : la) {
      Collections.sort(l);
    }
    la.sort(new LexicographicalListComparator());
    for (List<Integer> l : lb) {
      Collections.sort(l);
    }
    lb.sort(new LexicographicalListComparator());
    return la.equals(lb);
  };

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
