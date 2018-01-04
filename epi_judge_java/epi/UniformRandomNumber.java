package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.RandomSequenceChecker;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class UniformRandomNumber {
  private static int zeroOneRandom() {
    Random gen = new Random();
    return gen.nextInt(2);
  }

  public static int uniformRandom(int lowerBound, int upperBound) {
    // Implement this placeholder.
    return 0;
  }

  private static boolean uniformRandomRunner(TestTimer timer, int lowerBound,
                                             int upperBound) {
    List<Integer> results = new ArrayList<>();
    timer.start();
    for (int i = 0; i < 100000; ++i) {
      results.add(uniformRandom(lowerBound, upperBound));
    }
    timer.stop();

    List<Integer> sequence = new ArrayList<>();
    for (Integer result : results) {
      sequence.add(result - lowerBound);
    }
    return RandomSequenceChecker.checkSequenceIsUniformlyRandom(
        sequence, upperBound - lowerBound + 1, 0.01);
  }

  @EpiTest(testfile = "uniform_random_number.tsv")
  public static void uniformRandomWrapper(TestTimer timer, int lowerBound,
                                          int upperBound)
      throws TestFailureException {
    RandomSequenceChecker.runFuncWithRetries(
        () -> uniformRandomRunner(timer, lowerBound, upperBound));
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
