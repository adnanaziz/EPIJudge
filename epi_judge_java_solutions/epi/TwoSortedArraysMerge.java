package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class TwoSortedArraysMerge {

  public static void mergeTwoSortedArrays(List<Integer> A, int m,
                                          List<Integer> B, int n) {

    int a = m - 1, b = n - 1, writeIdx = m + n - 1;
    while (a >= 0 && b >= 0) {
      A.set(writeIdx--, A.get(a) > B.get(b) ? A.get(a--) : B.get(b--));
    }
    while (b >= 0) {
      A.set(writeIdx--, B.get(b--));
    }
  }

  @EpiTest(testDataFile = "two_sorted_arrays_merge.tsv")
  public static List<Integer>
  mergeTwoSortedArraysWrapper(List<Integer> A, int m, List<Integer> B, int n) {
    mergeTwoSortedArrays(A, m, B, n);
    return A;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "TwoSortedArraysMerge.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
