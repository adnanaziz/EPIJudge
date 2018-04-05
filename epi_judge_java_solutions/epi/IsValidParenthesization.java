package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;

public class IsValidParenthesization {
  @EpiTest(testfile = "is_valid_parenthesization.tsv")
  public static boolean isWellFormed(String s) {
    Deque<Character> leftChars = new ArrayDeque<>();
    final Map<Character, Character> LOOKUP =
        new HashMap<Character, Character>() {
          {
            put('(', ')');
            put('{', '}');
            put('[', ']');
          }
        };
    for (int i = 0; i < s.length(); ++i) {
      if (LOOKUP.get(s.charAt(i)) != null) {
        leftChars.addFirst(s.charAt(i));
      } else if (leftChars.isEmpty() ||
                 LOOKUP.get(leftChars.removeFirst()) != s.charAt(i)) {
        return false; // Unmatched right char.
      }
    }
    return leftChars.isEmpty();
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
