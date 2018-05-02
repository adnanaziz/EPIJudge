package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.Arrays;
import java.util.List;

public class PrettyPrinting {
  @EpiTest(testDataFile = "pretty_printing.tsv")

  public static int minimumMessiness(List<String> words, int lineLength) {

    // minimumMessiness[i] is the minimum messiness when placing
    // words.subList(0, i + 1).
    int[] minimumMessiness = new int[words.size()];
    Arrays.fill(minimumMessiness, Integer.MAX_VALUE);
    int numRemainingBlanks = lineLength - words.get(0).length();
    minimumMessiness[0] = numRemainingBlanks * numRemainingBlanks;
    for (int i = 1; i < words.size(); ++i) {
      numRemainingBlanks = lineLength - words.get(i).length();
      minimumMessiness[i] =
          minimumMessiness[i - 1] + numRemainingBlanks * numRemainingBlanks;
      // Try adding words.get(i - 1), words.get(i - 2), ...
      for (int j = i - 1; j >= 0; --j) {
        numRemainingBlanks -= (words.get(j).length() + 1);
        if (numRemainingBlanks < 0) {
          // Not enough space to add more words.
          break;
        }
        int firstJMessiness = j - 1 < 0 ? 0 : minimumMessiness[j - 1];
        int currentLineMessiness = numRemainingBlanks * numRemainingBlanks;
        minimumMessiness[i] = Math.min(minimumMessiness[i],
                                       firstJMessiness + currentLineMessiness);
      }
    }
    return minimumMessiness[words.size() - 1];
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "PrettyPrinting.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
