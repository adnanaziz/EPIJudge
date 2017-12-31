package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestFailureException;

public class RunLengthCompression {

  public static String decoding(String s) {
    // Implement this placeholder.
    return "";
  }

  public static String encoding(String s) {
    // Implement this placeholder.
    return "";
  }

  @EpiTest(testfile = "run_length_compression.tsv")
  public static void rleTester(String encoded, String decoded)
      throws TestFailureException {
    if (!decoding(encoded).equals(decoded)) {
      throw new TestFailureException("Decoding failed");
    }
    if (!encoding(decoded).equals(encoded)) {
      throw new TestFailureException("Encoding failed");
    }
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
