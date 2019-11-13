package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class SortAlmostSortedArray {

  public static List<Integer>
  sortApproximatelySortedData(Iterator<Integer> sequence, int k) {

    PriorityQueue<Integer> minHeap = new PriorityQueue<>();
    // Adds the first k elements into minHeap. Stop if there are fewer than k
    // elements.
    for (int i = 0; i < k && sequence.hasNext(); ++i) {
      minHeap.add(sequence.next());
    }

    List<Integer> result = new ArrayList<>();
    // For every new element, add it to minHeap and extract the smallest.
    while (sequence.hasNext()) {
      minHeap.add(sequence.next());
      Integer smallest = minHeap.remove();
      result.add(smallest);
    }

    // sequence is exhausted, iteratively extracts the remaining elements.
    result.addAll(Stream.generate(minHeap::remove)
                      .limit(minHeap.size())
                      .collect(Collectors.toList()));
    return result;
  }

  @EpiTest(testDataFile = "sort_almost_sorted_array.tsv")
  public static List<Integer>
  sortApproximatelySortedDataWrapper(List<Integer> sequence, int k) {
    return sortApproximatelySortedData(sequence.iterator(), k);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SortAlmostSortedArray.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
