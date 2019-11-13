package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.List;

public class IntersectSortedArrays {
  @EpiTest(testDataFile = "intersect_sorted_arrays.tsv")

  public static List<Integer> intersectTwoSortedArrays(List<Integer> A,
                                                       List<Integer> B) {

    List<Integer> intersectionAB = new ArrayList<>();
    for (int i = 0; i < A.size(); ++i) {
      if ((i == 0 || !A.get(i).equals(A.get(i - 1))) && B.contains(A.get(i))) {
        intersectionAB.add(A.get(i));
      }
    }
    return intersectionAB;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "IntersectSortedArrays.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
