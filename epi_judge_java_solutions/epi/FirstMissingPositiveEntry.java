package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.Collections;
import java.util.List;
import java.util.stream.IntStream;

public class FirstMissingPositiveEntry {
  @EpiTest(testDataFile = "first_missing_positive_entry.tsv")

  public static int findFirstMissingPositive(List<Integer> A) {

    // Record which values are present by writing A.get(i) to index A.get(i) - 1
    // if A.get(i) is between 1 and A.size(), inclusive. We save the value at
    // index A.get(i) - 1 by swapping it with the entry at i. If A.get(i) is
    // negative or greater than n, we just advance i.
    for (int i = 0; i < A.size(); ++i) {
      while (0 < A.get(i) && A.get(i) <= A.size() &&
             !A.get(A.get(i) - 1).equals(A.get(i))) {
        Collections.swap(A, i, A.get(i) - 1);
      }
    }

    // Second pass through A to search for the first index i such that A.get(i)
    // != i + 1, indicating that i + 1 is absent. If all numbers between 1 and
    // A.size() are present, the smallest missing positive is A.size() + 1.
    return IntStream.range(0, A.size())
               .filter(i -> A.get(i) != i + 1)
               .findFirst()
               .orElse(A.size()) +
        1;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "FirstMissingPositiveEntry.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
