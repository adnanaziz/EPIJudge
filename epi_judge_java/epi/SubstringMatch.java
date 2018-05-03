package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
public class SubstringMatch {
  @EpiTest(testDataFile = "substring_match.tsv")

  // Returns the index of the first character of the substring if found, -1
  // otherwise.
  public static int rabinKarp(String t, String s) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "SubstringMatch.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
