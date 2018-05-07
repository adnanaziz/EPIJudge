package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class SearchUnknownLengthArray {
  @EpiTest(testDataFile = "search_unknown_length_array.tsv")

  public static int binarySearchUnknownLength(List<Integer> A, int k) {

    // Find a range where k exists, if it's present.
    int p = 0;
    while (true) {
      try {
        int idx = (1 << p) - 1; // 2^p - 1.
        if (A.get(idx) == k) {
          return idx;
        } else if (A.get(idx) > k) {
          break;
        }
      } catch (IndexOutOfBoundsException e) {
        break;
      }
      ++p;
    }

    // Binary search between indices 2^(p - 1) and 2^p - 2, inclusive.
    int left = Math.max(0, 1 << (p - 1)), right = (1 << p) - 2;
    while (left <= right) {
      int mid = left + ((right - left) / 2);
      try {
        if (A.get(mid) == k) {
          return mid;
        } else if (A.get(mid) > k) {
          right = mid - 1;
        } else { // A.get(mid) < k
          left = mid + 1;
        }
      } catch (Exception e) {
        right = mid - 1; // Search the left part if out-of-bound.
      }
    }
    return -1; // Nothing matched k.
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SearchUnknownLengthArray.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
