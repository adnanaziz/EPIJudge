package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;

import java.util.List;
public class DefectiveJugs {
  @EpiUserType(ctorParams = {int.class, int.class})

  public static class Jug {
    public int low, high;

    public Jug() {}

    public Jug(int low, int high) {
      this.low = low;
      this.high = high;
    }
  }

  @EpiTest(testDataFile = "defective_jugs.tsv")

  public static boolean checkFeasible(List<Jug> jugs, int L, int H) {
    // TODO - you fill in here.
    return true;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "DefectiveJugs.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
