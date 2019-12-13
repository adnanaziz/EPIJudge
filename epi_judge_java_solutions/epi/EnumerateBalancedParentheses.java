package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.function.BiPredicate;

public class EnumerateBalancedParentheses {
  @EpiTest(testDataFile = "enumerate_balanced_parentheses.tsv")

  public static List<String> generateBalancedParentheses(int numPairs) {

    List<String> result = new ArrayList<>();
    directedGenerateBalancedParentheses(numPairs, numPairs, /*validPrefix=*/"",
                                        result);
    return result;
  }

  private static void
  directedGenerateBalancedParentheses(int numLeftParensNeeded,
                                      int numRightParensNeeded,
                                      String validPrefix, List<String> result) {
    if (numRightParensNeeded == 0) {
      result.add(validPrefix);
      return;
    }

    if (numLeftParensNeeded > 0) { // Able to insert '('.
      directedGenerateBalancedParentheses(numLeftParensNeeded - 1,
                                          numRightParensNeeded,
                                          validPrefix + "(", result);
    }
    if (numLeftParensNeeded < numRightParensNeeded) { // Able to insert ')'.
      directedGenerateBalancedParentheses(numLeftParensNeeded,
                                          numRightParensNeeded - 1,
                                          validPrefix + ")", result);
    }
  }

  @EpiTestComparator
  public static boolean comp(List<String> expected, List<String> result) {
    if (result == null) {
      return false;
    }
    Collections.sort(expected);
    Collections.sort(result);
    return expected.equals(result);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "EnumerateBalancedParentheses.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
