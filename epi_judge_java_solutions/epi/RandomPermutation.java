package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.RandomSequenceChecker;
import epi.test_framework.TestFailure;
import epi.test_framework.TimedExecutor;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class RandomPermutation {

  public static List<Integer> computeRandomPermutation(int n) {

    List<Integer> permutation =
        IntStream.range(0, n).boxed().collect(Collectors.toList());
    OfflineSampling.randomSampling(permutation.size(), permutation);
    return permutation;
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

  private static boolean computeRandomPermutationRunner(TimedExecutor executor,
                                                        int n)
      throws Exception {
    List<List<Integer>> results = new ArrayList<>();

    executor.run(() -> {
      for (int i = 0; i < 1000000; ++i) {
        results.add(computeRandomPermutation(n));
      }
    });

    List<Integer> sequence = new ArrayList<>();
    for (List<Integer> result : results) {
      sequence.add(permutationIndex(result));
    }
    return RandomSequenceChecker.checkSequenceIsUniformlyRandom(
        sequence, factorial(n), 0.01);
  }

  @EpiTest(testDataFile = "random_permutation.tsv")
  public static void computeRandomPermutationWrapper(TimedExecutor executor,
                                                     int n) throws Exception {
    RandomSequenceChecker.runFuncWithRetries(
        () -> computeRandomPermutationRunner(executor, n));
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "RandomPermutation.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
