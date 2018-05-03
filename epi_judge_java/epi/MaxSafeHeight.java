package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
public class MaxSafeHeight {
  @EpiTest(testDataFile = "max_safe_height.tsv")

  public static int getHeight(int cases, int drops) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MaxSafeHeight.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
