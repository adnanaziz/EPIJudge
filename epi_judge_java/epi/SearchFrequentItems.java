package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.GenericTestHandler;

import java.util.Collections;
import java.util.List;
import java.util.function.BiPredicate;
import java.util.stream.Collectors;

public class SearchFrequentItems {
  public static List<String> searchFrequentItems(Iterable<String> stream, int k) {
    // Implement this placeholder.
    return null;
  }

  @EpiTest(testfile = "search_frequent_items.tsv")
  public static List<String> searchFrequentItemsWrapper(int k, List<String> data) {
    return searchFrequentItems(data, k);
  }

  @EpiTestComparator
  public static BiPredicate<List<String>, List<String>> comp = (a, b) -> {
    Collections.sort(a);
    Collections.sort(b);
    return a.equals(b);
  };

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
