package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.LexicographicalListComparator;
import epi.test_framework.GenericTestHandler;

import java.util.List;
import java.util.function.BiPredicate;

public class EnumeratePalindromicDecompositions {
  @EpiTest(testfile = "enumerate_palindromic_decompositions.tsv")

  public static List<List<String>> palindromeDecompositions(String input) {
    // Implement this placeholder.
    return null;
  }

  @EpiTestComparator
      public static BiPredicate < List<List<String>>,
      List < List<String>>> comp = (expected, result) -> {
    if (result == null) {
      return false;
    }
    expected.sort(new LexicographicalListComparator<>());
    result.sort(new LexicographicalListComparator<>());
    return expected.equals(result);
  };

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
