package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class LeftRightJustifyText {
  @EpiTest(testDataFile = "left_right_justify_text.tsv")

  public static List<String> justifyText(List<String> words, int L) {

    int currLineLength = 0;
    List<String> result = new ArrayList<>();
    List<StringBuilder> currLine = new ArrayList<>();
    for (String word : words) {
      if (currLineLength + word.length() + currLine.size() > L) {
        // Distribute equally between words in curr_line.
        for (int i = 0; i < L - currLineLength; ++i) {
          currLine.get(i % Math.max(currLine.size() - 1, 1)).append(' ');
        }
        result.add(String.join("", currLine));
        currLine = new ArrayList<>();
        currLineLength = 0;
      }
      currLine.add(new StringBuilder(word));
      currLineLength += word.length();
    }
    // Handles the last line. Last line is to be left-aligned.
    result.add(
        String.join(" ", currLine) +
        String.join("", Collections.nCopies(
                            L - currLineLength - (currLine.size() - 1), " ")));
    return result;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "LeftRightJustifyText.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
