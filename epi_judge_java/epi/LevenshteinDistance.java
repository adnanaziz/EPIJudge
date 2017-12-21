package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class LevenshteinDistance {
  @EpiTest(testfile = "levenshtein_distance.tsv")

  public static int levenshteinDistance(String A, String B) {
    // Implement this placeholder.
    return 0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
