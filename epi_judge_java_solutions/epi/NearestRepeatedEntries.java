package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class NearestRepeatedEntries {
  @EpiTest(testDataFile = "nearest_repeated_entries.tsv")

  public static int findNearestRepetition(List<String> paragraph) {

    Map<String, Integer> wordToLatestIndex = new HashMap<>();
    int nearestRepeatedDistance = Integer.MAX_VALUE;
    for (int i = 0; i < paragraph.size(); ++i) {
      if (wordToLatestIndex.containsKey(paragraph.get(i))) {
        nearestRepeatedDistance =
            Math.min(nearestRepeatedDistance,
                     i - wordToLatestIndex.get(paragraph.get(i)));
      }
      wordToLatestIndex.put(paragraph.get(i), i);
    }
    return nearestRepeatedDistance != Integer.MAX_VALUE
        ? nearestRepeatedDistance
        : -1;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "NearestRepeatedEntries.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
