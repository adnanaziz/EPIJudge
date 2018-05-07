package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class SearchShiftedSortedArray {
  @EpiTest(testDataFile = "search_shifted_sorted_array.tsv")

  public static int searchSmallest(List<Integer> A) {

    int left = 0, right = A.size() - 1;
    while (left < right) {
      int mid = left + ((right - left) / 2);
      if (A.get(mid) > A.get(right)) {
        // Minimum must be in A.subList(mid + 1, right + 1).
        left = mid + 1;
      } else { // A.get(mid) < A.get(right).
        // Minimum cannot be in A.subList(mid + 1, right + 1) so it must be in
        // A.sublist(left, mid + 1).
        right = mid;
      }
    }
    // Loop ends when left == right.
    return left;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SearchShiftedSortedArray.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
