package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
public class LeftRightJustifyText {
  @EpiTest(testDataFile = "left_right_justify_text.tsv")

  public static List<String> justifyText(List<String> words, int L) {
    // TODO - you fill in here.
    return null;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "LeftRightJustifyText.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
