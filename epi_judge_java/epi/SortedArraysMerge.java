package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class SortedArraysMerge {

  @EpiTest(testfile = "sorted_arrays_merge.tsv")

  public static List<Integer>
  mergeSortedArrays(List<List<Integer>> sortedArrays) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
