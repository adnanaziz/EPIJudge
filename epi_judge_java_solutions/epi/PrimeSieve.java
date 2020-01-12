package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class PrimeSieve {

  @EpiTest(testDataFile = "prime_sieve.tsv")
  // Given n, return all primes up to and including n.
  public static List<Integer> generatePrimes(int n) {

    if (n < 2) {
      return Collections.emptyList();
    }
    final int size = (int)Math.floor(0.5 * (n - 3)) + 1;
    List<Integer> primes = new ArrayList<>();
    primes.add(2);
    // isPrime.get(i) represents whether (2i + 3) is prime or not.
    // For example, isPrime.get(0) represents 3 is prime or not,
    // isPrime.get(1) represents 5, isPrime.get(2) represents 7, etc.
    // Initially, set each to true. Then use sieving to eliminate nonprimes.
    List<Boolean> isPrime = new ArrayList<>(Collections.nCopies(size, true));
    for (long i = 0; i < size; ++i) {
      if (isPrime.get((int)i)) {
        int p = (((int)i * 2) + 3);
        primes.add(p);
        // Sieving from p^2, whose value is (4i^2 + 12i + 9). The index of this
        // value in isPrime is (2i^2 + 6i + 3) because isPrime.get(i) represents
        // 2i + 3.
        //
        // Note that we need to use long type for j because p^2 might overflow.
        for (long j = ((i * i) * 2) + 6 * i + 3; j < size; j += p) {
          isPrime.set((int)j, false);
        }
      }
    }
    return primes;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "PrimeSieve.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
