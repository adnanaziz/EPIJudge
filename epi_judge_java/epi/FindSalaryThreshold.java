package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class FindSalaryThreshold {
  @EpiTest(testfile = "find_salary_threshold.tsv")

  public static double findSalaryCap(int targetPayroll,
                                     List<Integer> currentSalaries) {
    // Implement this placeholder.
    return 0.0;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
