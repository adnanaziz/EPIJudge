package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

import java.util.List;

public class Bonus {

  private static class EmployeeData {
    public Integer productivity;
    public Integer index;

    public EmployeeData(Integer productivity, Integer index) {
      this.productivity = productivity;
      this.index = index;
    }
  }

  @EpiTest(testfile = "bonus.tsv")

  public static Integer calculateBonus(List<Integer> productivity) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
