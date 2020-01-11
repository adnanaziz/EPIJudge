package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
public class FindSalaryThreshold {
  @EpiTest(testDataFile = "find_salary_threshold.tsv")

  public static double findSalaryCap(int targetPayroll,
                                     List<Integer> currentSalaries) {
    // TODO - you fill in here.
    return 0.0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "FindSalaryThreshold.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
