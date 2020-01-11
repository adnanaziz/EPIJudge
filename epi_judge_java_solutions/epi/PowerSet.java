package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.GenericTest;
import epi.test_framework.LexicographicalListComparator;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class PowerSet {
  @EpiTest(testDataFile = "power_set.tsv")

  public static List<List<Integer>> generatePowerSet(List<Integer> inputSet) {

    List<List<Integer>> powerSet = new ArrayList<>();
    directedPowerSet(inputSet, 0, new ArrayList<Integer>(), powerSet);
    return powerSet;
  }

  // Generate all subsets whose intersection with inputSet[0], ...,
  // inputSet[toBeSelected - 1] is exactly selectedSoFar.
  private static void directedPowerSet(List<Integer> inputSet, int toBeSelected,
                                       List<Integer> selectedSoFar,
                                       List<List<Integer>> powerSet) {
    if (toBeSelected == inputSet.size()) {
      powerSet.add(new ArrayList<>(selectedSoFar));
      return;
    }
    // Generate all subsets that contain inputSet[toBeSelected].
    selectedSoFar.add(inputSet.get(toBeSelected));
    directedPowerSet(inputSet, toBeSelected + 1, selectedSoFar, powerSet);
    // Generate all subsets that do not contain inputSet[toBeSelected].
    selectedSoFar.remove(selectedSoFar.size() - 1);
    directedPowerSet(inputSet, toBeSelected + 1, selectedSoFar, powerSet);
  }

  @EpiTestComparator
  public static boolean comp(List<List<Integer>> expected,
                             List<List<Integer>> result) {
    if (result == null) {
      return false;
    }
    for (List<Integer> l : expected) {
      Collections.sort(l);
    }
    expected.sort(new LexicographicalListComparator<>());
    for (List<Integer> l : result) {
      Collections.sort(l);
    }
    result.sort(new LexicographicalListComparator<>());
    return expected.equals(result);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "PowerSet.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
