package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;

public class StringDecompositionsIntoDictionaryWords {
  @EpiTest(testDataFile = "string_decompositions_into_dictionary_words.tsv")

  public static List<Integer> findAllSubstrings(String s, List<String> words) {

    Map<String, Long> wordToFreq = words.stream().collect(
        Collectors.groupingBy(Function.identity(), Collectors.counting()));

    int unitSize = words.get(0).length();
    List<Integer> result = new ArrayList<>();
    for (int i = 0; i + unitSize * words.size() <= s.length(); ++i) {
      if (matchAllWordsInDict(s, wordToFreq, i, words.size(), unitSize)) {
        result.add(i);
      }
    }
    return result;
  }

  private static boolean matchAllWordsInDict(String s,
                                             Map<String, Long> wordToFreq,
                                             int start, int numWords,
                                             int unitSize) {
    Map<String, Integer> currStringToFreq = new HashMap<>();
    for (int i = 0; i < numWords; ++i) {
      String currWord =
          s.substring(start + i * unitSize, start + (i + 1) * unitSize);
      Long freq = wordToFreq.get(currWord);
      if (freq == null) {
        return false;
      }
      currStringToFreq.put(currWord,
                           currStringToFreq.getOrDefault(currWord, 0) + 1);
      if (currStringToFreq.get(currWord) > freq) {
        // currWord occurs too many times for a match to be possible.
        return false;
      }
    }
    return true;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, "StringDecompositionsIntoDictionaryWords.java",
                        new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
