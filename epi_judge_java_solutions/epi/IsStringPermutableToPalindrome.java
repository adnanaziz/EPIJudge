package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.HashSet;
import java.util.Set;

public class IsStringPermutableToPalindrome {
  @EpiTest(testDataFile = "is_string_permutable_to_palindrome.tsv")

  public static boolean canFormPalindrome(String s) {

    Set<Character> charsWithOddFrequency = new HashSet<>();
    for (int i = 0; i < s.length(); i++) {
      char c = s.charAt(i);
      if (charsWithOddFrequency.contains(c)) {
        // c now has appeared an even number of times.
        charsWithOddFrequency.remove(c);
      } else {
        // c now has appeared an odd number of times.
        charsWithOddFrequency.add(c);
      }
    }
    // A string can be permuted to form a palindrome if and only if the number
    // of chars whose frequencies is odd is at most 1.
    return charsWithOddFrequency.size() <= 1;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "IsStringPermutableToPalindrome.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
