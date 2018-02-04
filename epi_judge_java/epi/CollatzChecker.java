package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class CollatzChecker {
  @EpiTest(testfile = "collatz_checker.tsv")

  public static boolean testCollatzConjecture(int n) {
    // Implement this placeholder.
    return true;
  }

  public static void main(String[] args) {
    GenericTest.runFromAnnotations(
        args, new Object() {}.getClass().getEnclosingClass());
  }
}
