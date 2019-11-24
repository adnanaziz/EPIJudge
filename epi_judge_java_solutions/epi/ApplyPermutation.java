package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.Collections;
import java.util.List;

public class ApplyPermutation {

  public static void applyPermutation(List<Integer> perm, List<Integer> A) {
    int i = 0;
    while (i < A.size()) {
      // swap only if the position is changed in perm
      if (perm.get(i) != i) {
        // swap elements in both the lists to ensure ordering
        Collections.swap(A, perm.get(i), i);
        Collections.swap(perm, perm.get(i), i);
      } else {
        // i is in right place, so move to next
        i++;
      }
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
