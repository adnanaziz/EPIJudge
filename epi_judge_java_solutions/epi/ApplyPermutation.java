package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.Collections;
import java.util.List;

public class ApplyPermutation {

  public static void applyPermutation(List<Integer> perm, List<Integer> A) {

    for (int i = 0; i < A.size(); ++i) {
      // Check if the element at index i has not been moved by checking if
      // perm.get(i) is nonnegative.
      int next = i;
      while (perm.get(next) >= 0) {
        Collections.swap(A, i, perm.get(next));
        int temp = perm.get(next);
        // Subtracts perm.size() from an entry in perm to make it negative,
        // which indicates the corresponding move has been performed.
        perm.set(next, perm.get(next) - perm.size());
        next = temp;
      }
    }

    // Restore perm.
    for (int i = 0; i < perm.size(); i++) {
      perm.set(i, perm.get(i) + perm.size());
    }
  }

  @EpiTest(testDataFile = "apply_permutation.tsv")
  public static List<Integer> applyPermutationWrapper(List<Integer> perm,
                                                      List<Integer> A) {
    applyPermutation(perm, A);
    return A;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "ApplyPermutation.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
