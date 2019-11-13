package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
public class InsertOperatorsInString {
  @EpiTest(testDataFile = "insert_operators_in_string.tsv")

  public static boolean expressionSynthesis(List<Integer> digits, int target) {
    // TODO - you fill in here.
    return true;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "InsertOperatorsInString.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
