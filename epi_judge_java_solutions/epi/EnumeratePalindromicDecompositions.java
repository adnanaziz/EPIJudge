package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.GenericTest;
import epi.test_framework.LexicographicalListComparator;

import java.util.ArrayList;
import java.util.List;
import java.util.function.BiPredicate;

public class EnumeratePalindromicDecompositions {
  @EpiTest(testDataFile = "enumerate_palindromic_decompositions.tsv")

  public static List<List<String>> palindromeDecompositions(String text) {

    List<List<String>> result = new ArrayList<>();
    directedPalindromeDecompositions(text, /*offset=*/0,
                                     new ArrayList<String>(), result);
    return result;
  }

  private static void
  directedPalindromeDecompositions(String text, int offset,
                                   List<String> partialPartition,
                                   List<List<String>> result) {
    if (offset == text.length()) {
      result.add(new ArrayList<>(partialPartition));
      return;
    }

    for (int i = offset + 1; i <= text.length(); ++i) {
      String prefix = text.substring(offset, i);
      if (isPalindrome(prefix)) {
        partialPartition.add(prefix);
        directedPalindromeDecompositions(text, i, partialPartition, result);
        partialPartition.remove(partialPartition.size() - 1);
      }
    }
  }

  private static boolean isPalindrome(String prefix) {
    for (int i = 0, j = prefix.length() - 1; i < j; ++i, --j) {
      if (prefix.charAt(i) != prefix.charAt(j)) {
        return false;
      }
    }
    return true;
  }

  @EpiTestComparator
  public static boolean comp(List<List<String>> expected,
                             List<List<String>> result) {
    if (result == null) {
      return false;
    }
    expected.sort(new LexicographicalListComparator<>());
    result.sort(new LexicographicalListComparator<>());
    return expected.equals(result);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "EnumeratePalindromicDecompositions.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
