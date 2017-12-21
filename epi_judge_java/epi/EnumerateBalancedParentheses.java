package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.GenericTestHandler;

import java.util.Collections;
import java.util.List;
import java.util.function.BiPredicate;

public class EnumerateBalancedParentheses {
  @EpiTest(testfile = "enumerate_balanced_parentheses.tsv")

  public static List<String> generateBalancedParentheses(int numPairs) {
    // Implement this placeholder.
    return null;
  }

  @EpiTestComparator
  @SuppressWarnings("unchecked")
  public static BiPredicate<Object, Object> comp = (Object a, Object b) -> {
    List<String> la = (List<String>) a;
    List<String> lb = (List<String>) b;
    Collections.sort(la);
    Collections.sort(lb);
    return la.equals(lb);
  };

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
