package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.LexicographicalListComparator;
import epi.test_framework.GenericTestHandler;

import java.util.Collections;
import java.util.List;
import java.util.function.BiPredicate;

public class Anagrams {
  @EpiTest(testfile = "anagrams.tsv")

  public static List<List<String>> findAnagrams(List<String> dictionary) {
    // Implement this placeholder.
    return null;
  }

  @EpiTestComparator
  @SuppressWarnings("unchecked")
  public static BiPredicate<Object, Object> comp = (Object a, Object b) -> {
    List<List<String>> la = (List<List<String>>) a;
    List<List<String>> lb = (List<List<String>>) b;
    for (List<String> l : la) {
      Collections.sort(l);
    }
    la.sort(new LexicographicalListComparator());
    for (List<String> l : lb) {
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
