package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Queue;
import java.util.Set;

public class StringTransformability {

  private static class StringWithDistance {
    public String candidateString;
    public Integer distance;

    public StringWithDistance(String candidateString, Integer distance) {
      this.candidateString = candidateString;
      this.distance = distance;
    }
  }

  @EpiTest(testDataFile = "string_transformability.tsv")

  // Uses BFS to find the least steps of transformation.

  public static int transformString(Set<String> D, String s, String t) {

    Set<String> visited = new HashSet<String>(D);
    Queue<StringWithDistance> q = new ArrayDeque<>();
    visited.remove(s); // Marks s as visited by erasing it.
    q.add(new StringWithDistance(s, 0));

    StringWithDistance f;
    while ((f = q.poll()) != null) {
      // Returns if we find a match.
      if (f.candidateString.equals(t)) {
        return f.distance; // Number of steps reaches t.
      }

      // Tries all possible transformations of f.candidateString.
      String str = f.candidateString;
      for (int i = 0; i < str.length(); ++i) {
        String strStart = i == 0 ? "" : str.substring(0, i);
        String strEnd = i + 1 < str.length() ? str.substring(i + 1) : "";
        for (char c = 'a'; c <= 'z'; ++c) { // Iterates through 'a' ~ 'z'.
          String modStr = strStart + c + strEnd;
          if (visited.contains(modStr)) {
            visited.remove(modStr);
            q.add(new StringWithDistance(modStr, f.distance + 1));
          }
        }
      }
    }

    return -1; // Cannot find a possible transformations.
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "StringTransformability.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
