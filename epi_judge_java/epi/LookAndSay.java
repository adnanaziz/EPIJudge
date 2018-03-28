package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class LookAndSay {
  @EpiTest(testfile = "look_and_say.tsv")

  public static String lookAndSay(int n) {
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
