package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class KthLargestElementInLongArray {

  public static int findKthLargestUnknownLength(Iterator<Integer> stream,
                                                int k) {

    ArrayList<Integer> candidates = new ArrayList<>(2 * k - 1);
    while (stream.hasNext()) {
      int x = stream.next();
      candidates.add(x);
      if (candidates.size() == 2 * k - 1) {
        // Reorders elements about k-th largest element with larger elements
        // appearing before it.
        KthLargestInArray.findKthLargest(k, candidates);
        // Resize to keep just the k largest elements seen so far.
        candidates.subList(k, candidates.size()).clear();
      }
    }
    // Finds the k-th largest element in candidates.
    return KthLargestInArray.findKthLargest(k, candidates);
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
