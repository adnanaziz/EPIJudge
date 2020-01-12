package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
public class PrettyPrinting {
  @EpiTest(testDataFile = "pretty_printing.tsv")

  public static int minimumMessiness(List<String> words, int lineLength) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "PrettyPrinting.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
