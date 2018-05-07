package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
public class BinomialCoefficients {
  @EpiTest(testDataFile = "binomial_coefficients.tsv")

  public static int computeBinomialCoefficient(int n, int k) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "BinomialCoefficients.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
