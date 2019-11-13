package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.RandomSequenceChecker;
import epi.test_framework.TestFailure;
import epi.test_framework.TimedExecutor;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.Random;

public class OnlineSampling {

  // Assumption: there are at least k elements in the stream.
  public static List<Integer> onlineRandomSample(Iterator<Integer> stream,
                                                 int k) {

    List<Integer> runningSample = new ArrayList<>(k);
    // Stores the first k elements.
    for (int i = 0; stream.hasNext() && i < k; ++i) {
      runningSample.add(stream.next());
    }

    // Have read the first k elements.
    int numSeenSoFar = k;
    Random randIdxGen = new Random();
    while (stream.hasNext()) {
      Integer x = stream.next();
      ++numSeenSoFar;
      // Generate a random number in [0, numSeenSoFar], and if this number is in
      // [0, k - 1], we replace that element from the sample with x.
      final int idxToReplace = randIdxGen.nextInt(numSeenSoFar);
      if (idxToReplace < k) {
        runningSample.set(idxToReplace, x);
      }
    }
    return runningSample;
  }

  private static boolean onlineRandomSampleRunner(TimedExecutor executor,
                                                  List<Integer> A, int k)
      throws Exception {
    List<List<Integer>> results = new ArrayList<>();

    executor.run(() -> {
      for (int i = 0; i < 1000000; ++i) {
        results.add(onlineRandomSample(A.iterator(), k));
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

  @EpiTest(testDataFile = "online_sampling.tsv")
  public static void onlineRandomSampleWrapper(TimedExecutor executor,
                                               List<Integer> stream, int k)
      throws Exception {
    RandomSequenceChecker.runFuncWithRetries(
        () -> onlineRandomSampleRunner(executor, stream, k));
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "OnlineSampling.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
