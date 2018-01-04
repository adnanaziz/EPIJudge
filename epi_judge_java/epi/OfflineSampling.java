package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.RandomSequenceChecker;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class OfflineSampling {
  public static void randomSampling(int k, List<Integer> A) {
    // Implement this placeholder.
    return;
  }

  private static boolean randomSamplingRunner(TestTimer timer, int k,
                                              List<Integer> A) {
    List<List<Integer>> results = new ArrayList<>();
    timer.start();
    for (int i = 0; i < 1000000; ++i) {
      randomSampling(k, A);
      results.add(new ArrayList<>(A.subList(0, k)));
    }
    timer.stop();

    int totalPossibleOutcomes =
        RandomSequenceChecker.binomialCoefficient(A.size(), k);
    Collections.sort(A);
    List<List<Integer>> combinations = new ArrayList<>();
    for (int i = 0; i < RandomSequenceChecker.binomialCoefficient(A.size(), k);
         ++i) {
      combinations.add(
          RandomSequenceChecker.computeCombinationIdx(A, A.size(), k, i));
    }
    List<Integer> sequence = new ArrayList<>();
    for (List<Integer> result : results) {
      Collections.sort(result);
      sequence.add(combinations.indexOf(result));
    }
    return RandomSequenceChecker.checkSequenceIsUniformlyRandom(
        sequence, totalPossibleOutcomes, 0.01);
  }

  @EpiTest(testfile = "offline_sampling.tsv")
  public static void randomSamplingWrapper(TestTimer timer, int k,
                                           List<Integer> A)
      throws TestFailureException {
    RandomSequenceChecker.runFuncWithRetries(
        () -> randomSamplingRunner(timer, k, A));
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
