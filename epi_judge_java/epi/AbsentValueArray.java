package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailure;

import java.util.BitSet;
import java.util.Iterator;
import java.util.List;

public class AbsentValueArray {

  public static int findMissingElement(Iterable<Integer> stream) {

    final int NUM_BUCKET = 1 << 16;
    int[] counter = new int[NUM_BUCKET];
    Iterator<Integer> s = stream.iterator();
    while (s.hasNext()) {
      int idx = s.next() >>> 16;
      ++counter[idx];
    }

    // Look for a bucket that contains less than (1 << 16) elements.
    final int BUCKET_CAPACITY = 1 << 16;
    int candidateBucket = 0;
    for (int i = 0; i < NUM_BUCKET; ++i) {
      if (counter[i] < BUCKET_CAPACITY) {
        candidateBucket = i;
        break;
      }
    }

    // Finds all IP addresses in the stream whose first 16 bits
    // are equal to candidateBucket.
    BitSet candidates = new BitSet(BUCKET_CAPACITY);
    s = stream.iterator(); // Search from the beginning again.
    while (s.hasNext()) {
      int x = s.next();
      int upperPartX = x >>> 16;
      if (candidateBucket == upperPartX) {
        // Records the presence of 16 LSB of x.
        int lowerPartX = ((1 << 16) - 1) & x;
        candidates.set(lowerPartX);
      }
    }

    for (int i = 0; i < BUCKET_CAPACITY; ++i) {
      if (!candidates.get(i)) {
        return (candidateBucket << 16) | i;
      }
    }

    throw new IllegalArgumentException("no missing element");
  }

  @EpiTest(testDataFile = "absent_value_array.tsv")
  public static void findMissingElementWrapper(List<Integer> stream)
      throws Exception {
    try {
      int res = findMissingElement(stream);
      if (stream.stream().filter(a -> a.equals(res)).findFirst().isPresent()) {
        throw new TestFailure(String.valueOf(res) + " appears in stream");
      }
    } catch (IllegalArgumentException e) {
      throw new TestFailure("Unexpected no missing element exception");
    }
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "AbsentValueArray.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
