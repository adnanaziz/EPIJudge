package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
public class EuclideanGcd {
  @EpiTest(testDataFile = "gcd.tsv")

  public static long GCD(long x, long y) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "EuclideanGcd.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
