package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class StringDecompositionsIntoDictionaryWords {
  @EpiTest(testfile = "string_decompositions_into_dictionary_words.tsv")

  public static List<Integer> findAllSubstrings(String s, List<String> words) {
    // Implement this placeholder.
    return null;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
