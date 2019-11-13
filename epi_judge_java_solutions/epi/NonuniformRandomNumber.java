package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.RandomSequenceChecker;
import epi.test_framework.TestFailure;
import epi.test_framework.TimedExecutor;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

public class NonuniformRandomNumber {

  public static int
  nonuniformRandomNumberGeneration(List<Integer> values,
                                   List<Double> probabilities) {

    List<Double> prefixSumOfProbabilities = new ArrayList<>();
    // Creating the endpoints for the intervals corresponding to the
    // probabilities.
    probabilities.stream().reduce(0.0, (left, right) -> {
      prefixSumOfProbabilities.add(left + right);
      return left + right;
    });

    Random r = new Random();
    // Get a random number in [0.0,1.0).
    final double uniform01 = r.nextDouble();
    // Find the index of the interval that uniform01 lies in.
    int it = Collections.binarySearch(prefixSumOfProbabilities, uniform01);
    if (it < 0) {
      // We want the index of the first element in the array which is
      // greater than the key.
      //
      // When a key is not present in the array, Collections.binarySearch()
      // returns the negative of 1 plus the smallest index whose entry
      // is greater than the key.
      //
      // Therefore, if the return value is negative, by taking its absolute
      // value minus 1, we get the desired index.
      final int intervalIdx = Math.abs(it) - 1;
      return values.get(intervalIdx);
    } else {
      // We have it >= 0, i.e., uniform01 equals an entry
      // in prefixSumOfProbabilities.
      //
      // Because we uniform01 is a random double, the probability of it
      // equalling an endpoint in prefixSumOfProbabilities is exceedingly low.
      // However, it is not 0, so to be robust we must consider this case.
      return values.get(it);
    }
  }

  private static boolean nonuniformRandomNumberGenerationRunner(
      TimedExecutor executor, List<Integer> values, List<Double> probabilities)
      throws Exception {
    final int N = 1000000;
    List<Integer> results = new ArrayList<>(N);

    executor.run(() -> {
      for (int i = 0; i < N; ++i) {
        results.add(nonuniformRandomNumberGeneration(values, probabilities));
      }
    });

    Map<Integer, Integer> counts = new HashMap<>();
    for (Integer result : results) {
      counts.put(result, counts.getOrDefault(result, 0) + 1);
    }
    for (int i = 0; i < values.size(); ++i) {
      final int v = values.get(i);
      final double p = probabilities.get(i);
      if (N * p < 50 || N * (1.0 - p) < 50) {
        continue;
      }
      final double sigma = Math.sqrt(N * p * (1.0 - p));
      if (Math.abs(counts.get(v) - (p * N)) > 5 * sigma) {
        return false;
      }
    }
    return true;
  }

  @EpiTest(testDataFile = "nonuniform_random_number.tsv")
  public static void nonuniformRandomNumberGenerationWrapper(
      TimedExecutor executor, List<Integer> values, List<Double> probabilities)
      throws Exception {
    RandomSequenceChecker.runFuncWithRetries(
        ()
            -> nonuniformRandomNumberGenerationRunner(executor, values,
                                                      probabilities));
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "NonuniformRandomNumber.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
