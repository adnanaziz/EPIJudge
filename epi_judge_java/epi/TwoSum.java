package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
public class TwoSum {
  @EpiTest(testDataFile = "two_sum.tsv")

  public static boolean hasTwoSum(List<Integer> A, int t) {
    // TODO - you fill in here.
    return true;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "TwoSum.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
