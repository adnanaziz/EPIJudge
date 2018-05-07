package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
public class Fibonacci {

  @EpiTest(testDataFile = "fibonacci.tsv")

  public static int fibonacci(int n) {
    // TODO - you fill in here.
    return -1;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "Fibonacci.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
