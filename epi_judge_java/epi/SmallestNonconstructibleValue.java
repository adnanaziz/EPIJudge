package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class SmallestNonconstructibleValue {
  @EpiTest(testfile = "smallest_nonconstructible_value.tsv")

  public static int smallestNonconstructibleValue(List<Integer> A) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
