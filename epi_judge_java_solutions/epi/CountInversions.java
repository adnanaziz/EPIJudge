package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.List;

public class CountInversions {
  @EpiTest(testDataFile = "count_inversions.tsv")

  public static int countInversions(List<Integer> A) {

    return countSubarrayInversions(A, 0, A.size());
  }

  // Return the number of inversions in A.subList(start, finish).
  private static int countSubarrayInversions(List<Integer> A, int start,
                                             int finish) {
    if (finish - start <= 1) {
      return 0;
    }

    int mid = start + ((finish - start) / 2);
    return countSubarrayInversions(A, start, mid) +
        countSubarrayInversions(A, mid, finish) +
        mergeSortAndCountInversionsAcrossSubarrays(A, start, mid, finish);
  }

  // Merge two sorted sublists AsubList(start, mid) and A.subList(mid, finish)
  // into A.subList(start, finish) and return the number of inversions across
  // A.subList(start, mid) and A.subList(mid, finish).
  private static int mergeSortAndCountInversionsAcrossSubarrays(List<Integer> A,
                                                                int start,
                                                                int mid,
                                                                int finish) {
    List<Integer> sortedA = new ArrayList<>();
    int leftStart = start, rightStart = mid, inversionCount = 0;

    while (leftStart < mid && rightStart < finish) {
      if (Integer.compare(A.get(leftStart), A.get(rightStart)) <= 0) {
        sortedA.add(A.get(leftStart++));
      } else {
        // A.subList(leftStart, mid) are the inversions of A[rightStart].
        inversionCount += mid - leftStart;
        sortedA.add(A.get(rightStart++));
      }
    }
    sortedA.addAll(A.subList(leftStart, mid));
    sortedA.addAll(A.subList(rightStart, finish));

    // Updates A with sortedA.
    for (Integer t : sortedA) {
      A.set(start++, t);
    }
    return inversionCount;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "CountInversions.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
