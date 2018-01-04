package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.RandomSequenceChecker;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.ArrayList;
import java.util.List;

public class RandomPermutation {

  public static List<Integer> computeRandomPermutation(int n) {
    // Implement this placeholder.
    return null;
  }

  private static int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
  }

  private static int permutationIndex(List<Integer> perm) {
    int idx = 0;
    int n = perm.size();
    for (int i = 0; i < perm.size(); ++i) {
      int a = perm.get(i);
      idx += a * factorial(n - 1);
      for (int j = i + 1; j < perm.size(); ++j) {
        if (perm.get(j) > a) {
          perm.set(j, perm.get(j) - 1);
        }
      }
      --n;
    }
    return idx;
  }

  private static boolean computeRandomPermutationRunner(TestTimer timer,
                                                        int n) {
    List<List<Integer>> results = new ArrayList<>();
    timer.start();
    for (int i = 0; i < 1000000; ++i) {
      results.add(computeRandomPermutation(n));
    }
    timer.stop();

    List<Integer> sequence = new ArrayList<>();
    for (List<Integer> result : results) {
      sequence.add(permutationIndex(result));
    }
    return RandomSequenceChecker.checkSequenceIsUniformlyRandom(
        sequence, factorial(n), 0.01);
  }

  @EpiTest(testfile = "random_permutation.tsv")
  public static void computeRandomPermutationWrapper(TestTimer timer, int n)
      throws TestFailureException {
    RandomSequenceChecker.runFuncWithRetries(
        () -> computeRandomPermutationRunner(timer, n));
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
