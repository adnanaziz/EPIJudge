package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.RandomSequenceChecker;
import epi.test_framework.TimedExecutor;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class OfflineSampling {

  public static void randomSampling(int k, List<Integer> A) {

    Random gen = new Random();
    for (int i = 0; i < k; ++i) {
      // Generate a random int in [i, A.size() - 1].
      Collections.swap(A, i, i + gen.nextInt(A.size() - i));
    }
  }

  private static boolean randomSamplingRunner(TimedExecutor executor, int k,
                                              List<Integer> A)
      throws Exception {
    List<List<Integer>> results = new ArrayList<>();

    executor.run(() -> {
      for (int i = 0; i < 1000000; ++i) {
        randomSampling(k, A);
        results.add(new ArrayList<>(A.subList(0, k)));
      }
    });

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

  @EpiTest(testDataFile = "offline_sampling.tsv")
  public static void randomSamplingWrapper(TimedExecutor executor, int k,
                                           List<Integer> A) throws Exception {
    RandomSequenceChecker.runFuncWithRetries(
        () -> randomSamplingRunner(executor, k, A));
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "OfflineSampling.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
