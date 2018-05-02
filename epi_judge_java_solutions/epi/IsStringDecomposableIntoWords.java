package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailure;
import epi.test_framework.TimedExecutor;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Set;

public class IsStringDecomposableIntoWords {

  public static List<String>
  decomposeIntoDictionaryWords(String domain, Set<String> dictionary) {

    int[] lastLength = new int[domain.length()];
    Arrays.fill(lastLength, -1);
    // When the algorithm finishes, lastLength[i] != -1 indicates
    // domain.substring(0, i + 1) has a valid decomposition, and the length of
    // the last string in the decomposition will be lastLength[i].

    for (int i = 0; i < domain.length(); ++i) {
      // If domain.substring(0, i + 1) is a dictionary word, set lastLength[i]
      // to the length of that word.
      if (dictionary.contains(domain.substring(0, i + 1))) {
        lastLength[i] = i + 1;
        continue;
      }

      // If domain.substring(0, i + 1) is not a dictionary word, we look for j <
      // i such that domain.substring(0, j + 1) has a valid decomposition and
      // domain.substring(j + 1, i + 1) is a dictionary word. If so, record the
      // length of that word in lastLength[i].
      for (int j = 0; j < i; ++j) {
        if (lastLength[j] != -1 &&
            dictionary.contains(domain.substring(j + 1, i + 1))) {
          lastLength[i] = i - j;
          break;
        }
      }
    }

    List<String> decompositions = new ArrayList<>();
    if (lastLength[lastLength.length - 1] != -1) {
      // domain can be assembled by valid words.
      int idx = domain.length() - 1;
      while (idx >= 0) {
        decompositions.add(
            domain.substring(idx + 1 - lastLength[idx], idx + 1));
        idx -= lastLength[idx];
      }
      Collections.reverse(decompositions);
    }
    return decompositions;
  }

  @EpiTest(testDataFile = "is_string_decomposable_into_words.tsv")
  public static void decomposeIntoDictionaryWordsWrapper(TimedExecutor executor,
                                                         String domain,
                                                         Set<String> dictionary,
                                                         Boolean decomposable)
      throws Exception {
    List<String> result =
        executor.run(() -> decomposeIntoDictionaryWords(domain, dictionary));

    if (!decomposable) {
      if (!result.isEmpty()) {
        throw new TestFailure("domain is not decomposable");
      }
      return;
    }

    if (result.stream().anyMatch(s -> !dictionary.contains(s))) {
      throw new TestFailure("Result uses words not in dictionary");
    }

    if (!String.join("", result).equals(domain)) {
      throw new TestFailure("Result is not composed into domain");
    }
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "IsStringDecomposableIntoWords.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
