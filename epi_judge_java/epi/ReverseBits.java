package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
public class ReverseBits {
  @EpiTest(testDataFile = "reverse_bits.tsv")
  public static long reverseBits(long x) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "ReverseBits.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
