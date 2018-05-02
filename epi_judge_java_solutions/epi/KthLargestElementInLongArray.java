package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;

public class KthLargestElementInLongArray {

  public static int findKthLargestUnknownLength(Iterator<Integer> stream,
                                                int k) {

    ArrayList<Integer> candidates = new ArrayList<>(2 * k - 1);
    while (stream.hasNext()) {
      int x = stream.next();
      candidates.add(x);
      if (candidates.size() == 2 * k - 1) {
        // Reorders elements about median with larger elements appearing before
        // the median.
        KthLargestInArray.findKthLargest(k, candidates);
        // Resize to keep just the k largest elements seen so far.
        candidates.subList(k, candidates.size()).clear();
      }
    }
    // Finds the k-th largest element in candidates.
    KthLargestInArray.findKthLargest(k, candidates);
    return candidates.get(k - 1);
  }

  @EpiTest(testDataFile = "kth_largest_element_in_long_array.tsv")
  public static int findKthLargestUnknownLengthWrapper(List<Integer> stream,
                                                       int k) {
    return findKthLargestUnknownLength(stream.iterator(), k);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "KthLargestElementInLongArray.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
