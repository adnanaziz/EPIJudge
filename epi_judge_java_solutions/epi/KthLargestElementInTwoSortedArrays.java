package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class KthLargestElementInTwoSortedArrays {
  @EpiTest(testDataFile = "kth_largest_element_in_two_sorted_arrays.tsv")

  public static int findKthNTwoSortedArrays(List<Integer> A, List<Integer> B,
                                            int k) {

    // Lower bound of elements we will choose in A.
    int b = Math.max(0, k - B.size());
    // Upper bound of elements we will choose in A.
    int t = Math.min(A.size(), k);

    while (b < t) {
      int x = b + ((t - b) / 2);
      int ax1 = (x <= 0 ? Integer.MIN_VALUE : A.get(x - 1));
      int ax = (x >= A.size() ? Integer.MAX_VALUE : A.get(x));
      int bkx1 = (k - x <= 0 ? Integer.MIN_VALUE : B.get(k - x - 1));
      int bkx = (k - x >= B.size() ? Integer.MAX_VALUE : B.get(k - x));

      if (ax < bkx1) {
        b = x + 1;
      } else if (ax1 > bkx) {
        t = x - 1;
      } else {
        // B.get(k - x - 1) <= A.get(x) && A.get(x - 1) < B.get(k - x).
        return Math.max(ax1, bkx1);
      }
    }

    int ab1 = b <= 0 ? Integer.MIN_VALUE : A.get(b - 1);
    int bkb1 = k - b - 1 < 0 ? Integer.MIN_VALUE : B.get(k - b - 1);
    return Math.max(ab1, bkb1);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "KthLargestElementInTwoSortedArrays.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
