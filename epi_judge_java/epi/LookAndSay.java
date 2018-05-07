package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
public class LookAndSay {
  @EpiTest(testDataFile = "look_and_say.tsv")

  public static String lookAndSay(int n) {
    // TODO - you fill in here.
    return "";
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "LookAndSay.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
