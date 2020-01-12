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

  @EpiTest(testDataFile = "bonus.tsv")

  public static Integer calculateBonus(List<Integer> productivity) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "Bonus.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
