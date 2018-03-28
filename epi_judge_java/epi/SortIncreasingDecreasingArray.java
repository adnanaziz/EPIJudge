package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class SortIncreasingDecreasingArray {
  @EpiTest(testfile = "sort_increasing_decreasing_array.tsv")

  public static List<Integer> sortKIncreasingDecreasingArray(List<Integer> A) {
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
