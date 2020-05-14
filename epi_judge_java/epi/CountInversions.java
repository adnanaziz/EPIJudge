package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
public class CountInversions {
  @EpiTest(testDataFile = "count_inversions.tsv")

  public static int countInversions(List<Integer> A) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "CountInversions.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
