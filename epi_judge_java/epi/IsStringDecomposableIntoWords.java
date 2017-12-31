package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

import java.util.List;
import java.util.Set;

public class IsStringDecomposableIntoWords {
  @EpiTest(testfile = "is_string_decomposable_into_words.tsv")

  public static List<String>
  decomposeIntoDictionaryWords(String domain, Set<String> dictionary) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
