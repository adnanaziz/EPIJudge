package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
public class CollatzChecker {
  @EpiTest(testDataFile = "collatz_checker.tsv")

  public static boolean testCollatzConjecture(int n) {
    // TODO - you fill in here.
    return false;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "CollatzChecker.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
