package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.PriorityQueue;

public class OnlineMedian {

  private static final int DEFAULT_INITIAL_CAPACITY = 16;

  public static List<Double> onlineMedian(Iterator<Integer> sequence) {

    // minHeap stores the larger half seen so far.
    PriorityQueue<Integer> minHeap = new PriorityQueue<>();
    // maxHeap stores the smaller half seen so far.
    PriorityQueue<Integer> maxHeap = new PriorityQueue<>(
        DEFAULT_INITIAL_CAPACITY, Collections.reverseOrder());
    List<Double> result = new ArrayList<>();

    while (sequence.hasNext()) {
      int x = sequence.next();
      minHeap.add(x);
      maxHeap.add(minHeap.remove());
      // Ensure minHeap and maxHeap have equal number of elements if
      // an even number of elements is read; otherwise, minHeap must have
      // one more element than maxHeap.
      if (maxHeap.size() > minHeap.size()) {
        minHeap.add(maxHeap.remove());
      }

      result.add((minHeap.size() == maxHeap.size()
                      ? 0.5 * (minHeap.peek() + maxHeap.peek())
                      : (double)minHeap.peek()));
    }
    return result;
  }

  @EpiTest(testDataFile = "online_median.tsv")
  public static List<Double> onlineMedianWrapper(List<Integer> sequence) {
    return onlineMedian(sequence.iterator());
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "OnlineMedian.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
