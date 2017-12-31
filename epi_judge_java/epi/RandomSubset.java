package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.RandomSequenceChecker;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class RandomSubset {

  // Returns a random k-sized subset of {0, 1, ..., n - 1}.
  public static List<Integer> randomSubset(int n, int k) {
    // Implement this placeholder.
    return null;
  }

  private static boolean randomSubsetRunner(TestTimer timer, int n, int k) {
    List<List<Integer>> results = new ArrayList<>();
    timer.start();
    for (int i = 0; i < 1000000; ++i) {
      results.add(randomSubset(n, k));
    }
    timer.stop();

    int totalPossibleOutcomes = RandomSequenceChecker.binomialCoefficient(n, k);
    List<Integer> A = new ArrayList<>(n);
    for (int i = 0; i < n; ++i) {
      A.add(i);
    }
    List<List<Integer>> combinations = new ArrayList<>();
    for (int i = 0; i < RandomSequenceChecker.binomialCoefficient(n, k); ++i) {
      combinations.add(RandomSequenceChecker.computeCombinationIdx(A, n, k, i));
    }
    List<Integer> sequence = new ArrayList<>();
    for (List<Integer> result : results) {
      Collections.sort(result);
      sequence.add(combinations.indexOf(result));
    }
    return RandomSequenceChecker.checkSequenceIsUniformlyRandom(
        sequence, totalPossibleOutcomes, 0.01);
  }

  @EpiTest(testfile = "random_subset.tsv")
  public static void randomSubsetWrapper(TestTimer timer, int n, int k)
      throws TestFailureException {
    RandomSequenceChecker.runFuncWithRetries(
        () -> randomSubsetRunner(timer, n, k));
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
