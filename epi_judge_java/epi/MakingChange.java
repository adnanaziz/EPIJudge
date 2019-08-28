package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
public class MakingChange {
  @EpiTest(testDataFile = "making_change.tsv")

  public static int changeMaking(int cents) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MakingChange.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
