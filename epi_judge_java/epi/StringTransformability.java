package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.Set;
public class StringTransformability {
  @EpiTest(testDataFile = "string_transformability.tsv")
  public static int transformString(Set<String> D, String s, String t) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "StringTransformability.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
