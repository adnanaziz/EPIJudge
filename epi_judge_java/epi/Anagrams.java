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
      public static BiPredicate < List<List<String>>,
      List < List<String>>> comp = (expected, result) -> {
    if (result == null) {
      return false;
    }
    for (List<String> l : expected) {
      Collections.sort(l);
    }
    expected.sort(new LexicographicalListComparator<>());
    for (List<String> l : result) {
      Collections.sort(l);
    }
    result.sort(new LexicographicalListComparator<>());
    return expected.equals(result);
  };

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
