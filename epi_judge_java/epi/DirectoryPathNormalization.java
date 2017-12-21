package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class DirectoryPathNormalization {
  @EpiTest(testfile = "directory_path_normalization.tsv")

  public static String shortestEquivalentPath(String path) {
    // Implement this placeholder.
    return "";
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
