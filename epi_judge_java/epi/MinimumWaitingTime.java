package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class MinimumWaitingTime {
  @EpiTest(testfile = "minimum_waiting_time.tsv")

  public static int minimumTotalWaitingTime(List<Integer> serviceTimes) {
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
