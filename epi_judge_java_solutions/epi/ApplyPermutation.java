package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.Collections;
import java.util.List;

public class ApplyPermutation {

  public static void applyPermutation(List<Integer> perm, List<Integer> A) {

    for (int i = 0; i < A.size(); ++i) {
      while (perm.get(i) != i) {
        Collections.swap(A, i, perm.get(i));
        Collections.swap(perm, i, perm.get(i));
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
