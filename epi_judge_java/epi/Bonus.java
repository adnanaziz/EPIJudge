package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

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
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
