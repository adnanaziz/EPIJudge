package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class IntAsArrayIncrement {

  @EpiTest(testDataFile = "int_as_array_increment.tsv")
  public static List<Integer> plusOne(List<Integer> A) {

    int n = A.size() - 1;
    A.set(n, A.get(n) + 1);
    for (int i = n; i > 0 && A.get(i) == 10; --i) {
      A.set(i, 0);
      A.set(i - 1, A.get(i - 1) + 1);
    }
    if (A.get(0) == 10) {
      // There is a carry-out, so we need one more digit to store the result.
      // A slick way to do this is to append a 0 at the end of the array,
      // and update the first entry to 1.
      A.set(0, 1);
      A.add(0);
    }
    return A;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "IntAsArrayIncrement.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
