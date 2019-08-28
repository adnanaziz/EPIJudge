package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.function.BiPredicate;

public class KLargestInHeap {

  private static class HeapEntry {
    public Integer index;
    public Integer value;

    public HeapEntry(Integer index, Integer value) {
      this.index = index;
      this.value = value;
    }
  }

  private static final int DEFAULT_INITIAL_CAPACITY = 16;

  @EpiTest(testDataFile = "k_largest_in_heap.tsv")

  public static List<Integer> kLargestInBinaryHeap(List<Integer> A, int k) {

    if (k <= 0) {
      return Collections.emptyList();
    }

    // Stores the (index, value)-pair in candidateMaxHeap. This heap is
    // ordered by the value field.
    PriorityQueue<HeapEntry> candidateMaxHeap =
        new PriorityQueue<>(DEFAULT_INITIAL_CAPACITY,
                            (o1, o2) -> Integer.compare(o2.value, o1.value));
    candidateMaxHeap.add(new HeapEntry(0, A.get(0)));
    List<Integer> result = new ArrayList<>();
    for (int i = 0; i < k; ++i) {
      Integer candidateIdx = candidateMaxHeap.peek().index;
      result.add(candidateMaxHeap.remove().value);

      Integer leftChildIdx = 2 * candidateIdx + 1;
      if (leftChildIdx < A.size()) {
        candidateMaxHeap.add(new HeapEntry(leftChildIdx, A.get(leftChildIdx)));
      }
      Integer rightChildIdx = 2 * candidateIdx + 2;
      if (rightChildIdx < A.size()) {
        candidateMaxHeap.add(
            new HeapEntry(rightChildIdx, A.get(rightChildIdx)));
      }
    }
    return result;
  }

  @EpiTestComparator
  public static boolean comp(List<Integer> expected, List<Integer> result) {
    if (result == null) {
      return false;
    }
    Collections.sort(expected);
    Collections.sort(result);
    return expected.equals(result);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "KLargestInHeap.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
