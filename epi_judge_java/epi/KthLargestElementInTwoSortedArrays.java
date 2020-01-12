package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
public class KthLargestElementInTwoSortedArrays {
  @EpiTest(testDataFile = "kth_largest_element_in_two_sorted_arrays.tsv")

  public static int findKthNTwoSortedArrays(List<Integer> A, List<Integer> B,
                                            int k) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "KthLargestElementInTwoSortedArrays.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
