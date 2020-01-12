package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailure;
import epi.test_framework.TimedExecutor;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class GrayCode {

  public static List<Integer> grayCode(int numBits) {

    List<Integer> result = new ArrayList<>(List.of(0));
    directedGrayCode(numBits, new HashSet<Integer>(List.of(0)), result);
    return result;
  }

  private static boolean directedGrayCode(int numBits, Set<Integer> history,
                                          List<Integer> result) {
    if (result.size() == (1 << numBits)) {
      return differsByOneBit(result.get(0), result.get(result.size() - 1));
    }

    for (int i = 0; i < numBits; ++i) {
      int previousCode = result.get(result.size() - 1);
      int candidateNextCode = previousCode ^ (1 << i);
      if (!history.contains(candidateNextCode)) {
        history.add(candidateNextCode);
        result.add(candidateNextCode);
        if (directedGrayCode(numBits, history, result)) {
          return true;
        }
        result.remove(result.size() - 1);
        history.remove(candidateNextCode);
      }
    }
    return false;
  }

  private static boolean differsByOneBit(int x, int y) {
    int bitDifference = x ^ y;
    return bitDifference != 0 && (bitDifference & (bitDifference - 1)) == 0;
  }

  @EpiTest(testDataFile = "gray_code.tsv")
  public static void grayCodeWrapper(TimedExecutor executor, int numBits)
      throws Exception {
    List<Integer> result = executor.run(() -> grayCode(numBits));

    int expectedSize = (1 << numBits);
    if (result.size() != expectedSize) {
      throw new TestFailure("Length mismatch: expected " +
                            String.valueOf(expectedSize) + ", got " +
                            String.valueOf(result.size()));
    }
    for (int i = 1; i < result.size(); i++)
      if (!differsByOneBit(result.get(i - 1), result.get(i))) {
        if (result.get(i - 1).equals(result.get(i))) {
          throw new TestFailure("Two adjacent entries are equal");
        } else {
          throw new TestFailure(
              "Two adjacent entries differ by more than 1 bit");
        }
      }

    Set<Integer> uniq = new HashSet<>(result);
    if (uniq.size() != result.size()) {
      throw new TestFailure("Not all entries are distinct: found " +
                            String.valueOf(result.size() - uniq.size()) +
                            " duplicates");
    }
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "GrayCode.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
