package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.function.BiPredicate;
import java.util.stream.Collectors;

public class SearchFrequentItems {

  public static List<String> searchFrequentItems(int k,
                                                 Iterable<String> stream) {

    // Finds the candidates which may occur > n / k times.
    String buf = "";
    Map<String, Integer> table = new HashMap<>();
    int n = 0; // Counts the number of strings.

    Iterator<String> sequence = stream.iterator();
    while (sequence.hasNext()) {
      buf = sequence.next();
      table.put(buf, table.getOrDefault(buf, 0) + 1);
      ++n;
      // Detecting k items in table, at least one of them must have exactly one
      // in it. We will discard those k items by one for each.
      if (table.size() == k) {
        List<String> delKeys = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : table.entrySet()) {
          if (entry.getValue() - 1 == 0) {
            delKeys.add(entry.getKey());
          } else {
            table.put(entry.getKey(), entry.getValue() - 1);
          }
        }
        for (String s : delKeys) {
          table.remove(s);
        }
      }
    }

    // Resets table for the following counting.
    table = table.entrySet().stream().collect(
        Collectors.toMap(e -> e.getKey(), e -> 0));

    // Counts the occurrence of each candidate word.
    sequence = stream.iterator();
    while (sequence.hasNext()) {
      buf = sequence.next();
      Integer it = table.get(buf);
      if (it != null) {
        table.put(buf, it + 1);
      }
    }

    final double threshold = (double)n / k;
    // Selects the word which occurs > n / k times.
    return table.entrySet()
        .stream()
        .filter(it -> threshold < (double)it.getValue())
        .map(it -> it.getKey())
        .collect(Collectors.toList());
  }

  @EpiTest(testDataFile = "search_frequent_items.tsv")
  public static List<String> searchFrequentItemsWrapper(int k,
                                                        List<String> stream) {
    return searchFrequentItems(k, stream);
  }

  @EpiTestComparator
  public static boolean comp(List<String> expected, List<String> result) {
    if (result == null) {
      return false;
    }
    Collections.sort(expected);
    Collections.sort(result);
    return expected.equals(result);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SearchFrequentItems.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
