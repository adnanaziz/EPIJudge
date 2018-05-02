package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.BitSet;
import java.util.Iterator;

public class AbsentValueArray {

  @EpiTest(testDataFile = "absent_value_array.tsv")
  public static int findMissingElement(Iterable<Integer> stream) {

    final int NUM_BUCKET = 1 << 16;
    int[] counter = new int[NUM_BUCKET];
    Iterator<Integer> s = stream.iterator();
    while (s.hasNext()) {
      int idx = s.next() >>> 16;
      ++counter[idx];
    }

    for (int i = 0; i < counter.length; ++i) {
      // Look for a bucket that contains less than NUM_BUCKET elements.
      if (counter[i] < NUM_BUCKET) {
        BitSet candidates = new BitSet(NUM_BUCKET);
        s = stream.iterator(); // Search from the beginning again.
        while (s.hasNext()) {
          int x = s.next();
          if (i == (x >>> 16)) {
            candidates.set(((NUM_BUCKET)-1) &
                           x); // Gets the lower 16 bits of x.
          }
        }

        for (int j = 0; j < (1 << 16); ++j) {
          if (!candidates.get(j)) {
            return (i << 16) | j;
          }
        }
      }
    }

    throw new IllegalArgumentException("no missing element");
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "AbsentValueArray.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
