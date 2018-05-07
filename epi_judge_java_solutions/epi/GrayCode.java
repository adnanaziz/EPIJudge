package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailure;
import epi.test_framework.TimedExecutor;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class GrayCode {

  public static List<Integer> grayCode(int numBits) {

    if (numBits == 0) {
      return new ArrayList<>(List.of(0));
    }

    // These implicitly begin with 0 at bit-index (numBits - 1).
    List<Integer> grayCodeNumBitsMinus1 = grayCode(numBits - 1);

    // Now, add a 1 at bit-index (numBits - 1) to all entries in
    // grayCodeNumBitsMinus1.
    int leadingBitOne = 1 << (numBits - 1);
    // Process in reverse order to achieve reflection of grayCodeNumBitsMinus1.
    for (int i = grayCodeNumBitsMinus1.size() - 1; i >= 0; --i) {
      grayCodeNumBitsMinus1.add(leadingBitOne | grayCodeNumBitsMinus1.get(i));
    }
    return grayCodeNumBitsMinus1;
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
