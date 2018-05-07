package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiTestComparator;
import epi.test_framework.LexicographicalListComparator;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.List;
import java.util.function.BiPredicate;

public class EnumeratePalindromicDecompositions {
  @EpiTest(testDataFile = "enumerate_palindromic_decompositions.tsv")

  public static List<List<String>> palindromeDecompositions(String input) {

    List<List<String>> result = new ArrayList<>();
    directedPalindromeDecompositions(input, 0, new ArrayList<String>(), result);
    return result;
  }

  private static void
  directedPalindromeDecompositions(String input, int offset,
                                   List<String> partialPartition,
                                   List<List<String>> result) {
    if (offset == input.length()) {
      result.add(new ArrayList<>(partialPartition));
      return;
    }

    for (int i = offset + 1; i <= input.length(); ++i) {
      String prefix = input.substring(offset, i);
      if (isPalindrome(prefix)) {
        partialPartition.add(prefix);
        directedPalindromeDecompositions(input, i, partialPartition, result);
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
  public static BiPredicate<List<List<String>>, List<List<String>>> comp =
      (expected, result) -> {
    if (result == null) {
      return false;
    }
    expected.sort(new LexicographicalListComparator<>());
    result.sort(new LexicographicalListComparator<>());
    return expected.equals(result);
  };

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "EnumeratePalindromicDecompositions.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
