package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.HashSet;
import java.util.Set;

public class CollatzChecker {
  @EpiTest(testDataFile = "collatz_checker.tsv")

  public static boolean testCollatzConjecture(int n) {

    // Stores odd numbers already tested to converge to 1.
    Set<Long> verifiedNumbers = new HashSet<>();

    // Starts from 3, since hypothesis holds trivially for 1 and 2.
    for (int i = 3; i <= n; i += 2) {
      Set<Long> sequence = new HashSet<>();
      long testI = i;
      while (testI >= i) {
        if (!sequence.add(testI)) {
          // We previously encountered testI, so the CollatzCheckerParallel
          // sequence has fallen into a loop. This disproves the hypothesis, so
          // we short-circuit, returning false.
          return false;
        }

        if ((testI % 2) != 0) { // Odd number
          if (!verifiedNumbers.add(testI)) {
            break; // testI has already been verified to converge to 1.
          }
          long nextTestI = 3 * testI + 1; // Multiply by 3 and add 1.
          if (nextTestI <= testI) {
            throw new ArithmeticException(
                "CollatzCheckerParallel sequence overflow for " + i);
          }
          testI = nextTestI;
        } else {
          testI /= 2; // Even number, halve it.
        }
      }
    }
    return true;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "CollatzChecker.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
