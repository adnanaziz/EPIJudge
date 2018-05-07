package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TimedExecutor;

public class ReverseWords {

  public static void reverseWords(char[] input) {

    int n = input.length;
    // First, reverses the whole string.
    reverse(input, 0, n - 1);

    // Second, Reverses each word in the string.
    int start = 0, finish = 0;
    while (start < n) {
      while (start < finish || start < n && input[start] == ' ') {
        ++start; // Skip spaces chars.
      }
      while (finish < start || finish < n && input[finish] != ' ') {
        ++finish; // Skip non-spaces chars.
      }
      reverse(input, start, finish - 1);
    }
  }

  private static void reverse(char[] array, int start, int end) {
    while (start < end) {
      char tmp = array[start];
      array[start++] = array[end];
      array[end--] = tmp;
    }
  }

  @EpiTest(testDataFile = "reverse_words.tsv")
  public static String reverseWordsWrapper(TimedExecutor executor, String s)
      throws Exception {
    char[] sCopy = s.toCharArray();

    executor.run(() -> reverseWords(sCopy));

    return String.valueOf(sCopy);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "ReverseWords.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
