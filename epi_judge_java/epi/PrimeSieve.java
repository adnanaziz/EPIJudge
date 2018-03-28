package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class PrimeSieve {
  @EpiTest(testfile = "prime_sieve.tsv")
  // Given n, return all primes up to and including n.
  public static List<Integer> generatePrimes(int n) {
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
