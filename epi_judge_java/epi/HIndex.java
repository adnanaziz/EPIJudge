package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
public class HIndex {
  @EpiTest(testDataFile = "h_index.tsv")
  public static int hIndex(List<Integer> citations) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "HIndex.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
