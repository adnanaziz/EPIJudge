package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
public class NumberOfTraversalsStaircase {
  @EpiTest(testDataFile = "number_of_traversals_staircase.tsv")

  public static int numberOfWaysToTop(int top, int maximumStep) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "NumberOfTraversalsStaircase.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
