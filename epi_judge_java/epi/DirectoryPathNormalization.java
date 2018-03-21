package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class DirectoryPathNormalization {
  @EpiTest(testfile = "directory_path_normalization.tsv")

  public static String shortestEquivalentPath(String path) {
    // Implement this placeholder.
    return "";
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
