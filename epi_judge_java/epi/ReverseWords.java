package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestTimer;

public class ReverseWords {

  public static void reverseWords(char[] input) {
    // Implement this placeholder.
    return;
  }

  @EpiTest(testfile = "reverse_words.tsv")
  public static String reverseWordsWrapper(TestTimer timer, String s) {
    char[] sCopy = s.toCharArray();

    timer.start();
    reverseWords(sCopy);
    timer.stop();

    return String.valueOf(sCopy);
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
