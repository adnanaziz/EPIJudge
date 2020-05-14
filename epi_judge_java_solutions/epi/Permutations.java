package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.GenericTest;
import epi.test_framework.LexicographicalListComparator;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Permutations {
  @EpiTest(testDataFile = "permutations.tsv")

  public static List<List<Integer>> permutations(List<Integer> A) {

    List<List<Integer>> result = new ArrayList<>();
    directedPermutations(0, A, result);
    return result;
  }

  private static void directedPermutations(int i, List<Integer> A,
                                           List<List<Integer>> result) {
    if (i == A.size() - 1) {
      result.add(new ArrayList<>(A));
      return;
    }

    // Try every possibility for A[i].
    for (int j = i; j < A.size(); ++j) {
      Collections.swap(A, i, j);
      // Generate all permutations for A.subList(i + 1, A.size()).
      directedPermutations(i + 1, A, result);
      Collections.swap(A, i, j);
    }
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
            .runFromAnnotations(args, "Permutations.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
