package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
public class ApplyPermutation {
  public static void applyPermutation(List<Integer> perm, List<Integer> A) {
    // TODO - you fill in here.
    return;
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
