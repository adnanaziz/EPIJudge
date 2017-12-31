package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;
import epi.test_framework.TestTimer;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class GrayCode {

  public static List<Integer> grayCode(int numBits) {
    // Implement this placeholder.
    return null;
  }

  private static boolean differsByOneBit(int x, int y) {
    int bitDifference = x ^ y;
    return bitDifference != 0 && (bitDifference & (bitDifference - 1)) == 0;
  }

  @EpiTest(testfile = "gray_code.tsv")
  public static void grayCodeWrapper(TestTimer timer, int numBits)
      throws TestFailureException {
    timer.start();
    List<Integer> result = grayCode(numBits);
    timer.stop();

    int expectedSize = (1 << numBits);
    if (result.size() != expectedSize) {
      throw new TestFailureException("Length mismatch: expected " +
                                     String.valueOf(expectedSize) + ", got " +
                                     String.valueOf(result.size()));
    }
    for (int i = 1; i < result.size(); i++)
      if (!differsByOneBit(result.get(i - 1), result.get(i))) {
        if (result.get(i - 1).equals(result.get(i))) {
          throw new TestFailureException("Two adjacent entries are equal");
        } else {
          throw new TestFailureException(
              "Two adjacent entries differ by more than 1 bit");
        }
      }

    Set<Integer> uniq = new HashSet<>(result);
    if (uniq.size() != result.size()) {
      throw new TestFailureException(
          "Not all entries are distinct: found " +
          String.valueOf(result.size() - uniq.size()) + " duplicates");
    }
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
