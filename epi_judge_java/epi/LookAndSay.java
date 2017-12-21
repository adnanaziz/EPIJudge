package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

public class LookAndSay {
  @EpiTest(testfile = "look_and_say.tsv")

  public static String lookAndSay(int n) {
    // Implement this placeholder.
    return "";
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
