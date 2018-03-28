package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class LeftRightJustifyText {
  @EpiTest(testfile = "left_right_justify_text.tsv")

  public static List<String> justifyText(List<String> words, int L) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
