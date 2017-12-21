package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.LexicographicalListComparator;
import epi.test_framework.GenericTestHandler;

import java.util.Collections;
import java.util.List;
import java.util.function.BiPredicate;

public class Permutations {
  @EpiTest(testfile = "permutations.tsv")

  public static List<List<Integer>> permutations(List<Integer> A) {
    // Implement this placeholder.
    return null;
  }

  @EpiTestComparator
  @SuppressWarnings("unchecked")
  public static BiPredicate<Object, Object> comp = (Object a, Object b) -> {
    List<List<Integer>> la = (List<List<Integer>>) a;
    List<List<Integer>> lb = (List<List<Integer>>) b;
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
