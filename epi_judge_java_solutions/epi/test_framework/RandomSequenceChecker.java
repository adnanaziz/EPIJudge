
package epi.test_framework;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Set;
import java.util.concurrent.Callable;

public class RandomSequenceChecker {
  private static int computeDeviationMultiplier(double allowedFalseNegative,
                                                int numRvs) {
    final double individualRvError = allowedFalseNegative / numRvs;
    final double[] ERROR_BOUNDS = {1 - 0.682689492137086, 1 - 0.954499736103642,
                                   1 - 0.997300203936740, 1 - 0.999936657516334,
                                   1 - 0.999999426696856, 1 - 0.999999998026825,
                                   1 - 0.999999999997440};

    for (int i = 0; i < ERROR_BOUNDS.length; ++i) {
      if (ERROR_BOUNDS[i] <= individualRvError) {
        return i + 1;
      }
    }
    return ERROR_BOUNDS.length + 1;
  }

  private static boolean checkFrequencies(List<Integer> seq, int n,
                                          double falseNegativeTolerance) {
    final double avg = (double)seq.size() / n;
    final int kIndiv = computeDeviationMultiplier(falseNegativeTolerance, n);
    final double p = 1.0 / n;
    final double sigmaIndiv = Math.sqrt(seq.size() * p * (1.0 - p));
    final double kSigmaIndiv = kIndiv * sigmaIndiv;
    // To make our testing meaningful "sufficiently large", we need to have
    // enough testing data.
    if (seq.size() * p < 50 || seq.size() * (1 - p) < 50) {
      return true; // Sample size is too small so we cannot use normal
                   // approximation
    }

    Map<Integer, Integer> indivFreqs = new HashMap<>();
    for (Integer a : seq) {
      indivFreqs.put(a, indivFreqs.getOrDefault(a, 0) + 1);
    }

    // Check that there are roughly seq.size()/n occurrences of key. By roughly
    // we mean the difference is less than k_sigma.
    return indivFreqs.values().stream().allMatch(
        freq -> Math.abs(avg - freq) <= kSigmaIndiv);
  }

  private static boolean checkPairsFrequencies(List<Integer> seq, int n,
                                               double falseNegativeTolerance) {
    List<Integer> seqPairs = new ArrayList<>();
    for (int i = 1; i < seq.size(); ++i) {
      seqPairs.add(seq.get(i - 1) * n + seq.get(i));
    }

    return checkFrequencies(seqPairs, n * n, falseNegativeTolerance);
  }

  private static boolean
  checkTriplesFrequencies(List<Integer> seq, int n,
                          double falseNegativeTolerance) {
    List<Integer> seqTriples = new ArrayList<>();
    for (int i = 2; i < seq.size(); ++i) {
      seqTriples.add(seq.get(i - 2) * n * n + seq.get(i - 1) * n + seq.get(i));
    }

    return checkFrequencies(seqTriples, n * n * n, falseNegativeTolerance);
  }

  private static boolean checkBirthdaySpacings(List<Integer> seq, int n) {
    final int expectedAvgRepetitionLength =
        (int)Math.ceil(Math.sqrt(Math.log(2.0) * 2.0 * n));
    final int numberOfSubarrays = seq.size() - expectedAvgRepetitionLength + 1;
    final int MIN_NUMBER_SUBARRAYS = 1000;
    if (numberOfSubarrays < MIN_NUMBER_SUBARRAYS) {
      return true; // Not enough subarrays for birthday spacing check
    }

    int numberOfSubarraysWithRepetitions = 0;
    for (int i = 0; i < seq.size() - expectedAvgRepetitionLength; ++i) {
      Set<Integer> seqWindow =
          new HashSet<>(seq.subList(i, i + expectedAvgRepetitionLength));
      numberOfSubarraysWithRepetitions +=
          (seqWindow.size() < expectedAvgRepetitionLength) ? 1 : 0;
    }

    final double COUNT_TOLERANCE = 0.4;
    return COUNT_TOLERANCE * numberOfSubarrays <=
        numberOfSubarraysWithRepetitions;
  }

  // seq is a sequence of integers, which should be in the range [0,n-1]. We
  // assume n << seq.size().
  public static boolean
  checkSequenceIsUniformlyRandom(List<Integer> seq, int n,
                                 double falseNegativeTolerance) {
    return checkFrequencies(seq, n, falseNegativeTolerance) &&
        checkPairsFrequencies(seq, n, falseNegativeTolerance) &&
        checkTriplesFrequencies(seq, n, falseNegativeTolerance) &&
        checkBirthdaySpacings(seq, n);
  }

  public static int binomialCoefficient(int n, int k) {
    if (n < k) {
      return 0;
    }
    if (k == 0 || k == n) {
      return 1;
    }
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
  }

  // Get the mth combination in lexicographical order from A (n elements) chosen
  // k at a time.
  public static List<Integer> computeCombinationIdx(List<Integer> A, int n,
                                                    int k, int m) {
    List<Integer> comb = new ArrayList<>();
    int a = n, b = k, x = (binomialCoefficient(n, k) - 1) - m;
    for (int i = 0; i < k; ++i) {
      --a;
      while (binomialCoefficient(a, b) > x) {
        --a;
      }
      comb.add(A.get(n - 1 - a));
      x -= binomialCoefficient(a, b);
      --b;
    }
    return comb;
  }

  public static void runFuncWithRetries(Callable<Boolean> func)
      throws Exception {
    final int NUM_RUNS = 5;
    for (int i = 0; i < NUM_RUNS; i++) {
      if (func.call()) {
        return;
      }
    }
    throw new TestFailure("Result is not a random permutation");
  }

  public static void main(String[] args) {
    Random gen = new Random();
    List<Integer> seq = new ArrayList<>();
    for (int i = 0; i < 1000000; ++i) {
      seq.add(gen.nextInt(10) + 1);
    }
    System.out.println(checkSequenceIsUniformlyRandom(seq, 10, 0.01));

    seq.clear();
    for (int i = 0; i < 1000000; ++i) {
      seq.add(gen.nextInt(11) + 1);
    }
    System.out.println(checkSequenceIsUniformlyRandom(seq, 10, 0.01));

    seq.clear();
    for (int i = 0; i < 1000000; ++i) {
      seq.add(i % 10);
    }
    System.out.println(checkSequenceIsUniformlyRandom(seq, 10, 0.01));
  }
}
