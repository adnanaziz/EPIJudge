package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class IsAnonymousLetterConstructible {
  @EpiTest(testfile = "is_anonymous_letter_constructible.tsv")

  public static boolean isLetterConstructibleFromMagazine(String letterText,
                                                          String magazineText) {
    // Implement this placeholder.
    return true;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
