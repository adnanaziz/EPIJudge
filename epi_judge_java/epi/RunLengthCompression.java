package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TestFailure;
public class RunLengthCompression {

  public static String decoding(String s) {
    // TODO - you fill in here.
    return "";
  }
  public static String encoding(String s) {
    // TODO - you fill in here.
    return "";
  }
  @EpiTest(testDataFile = "run_length_compression.tsv")
  public static void rleTester(String encoded, String decoded)
      throws TestFailure {
    if (!decoding(encoded).equals(decoded)) {
      throw new TestFailure("Decoding failed");
    }
    if (!encoding(decoded).equals(encoded)) {
      throw new TestFailure("Encoding failed");
    }
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "RunLengthCompression.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
