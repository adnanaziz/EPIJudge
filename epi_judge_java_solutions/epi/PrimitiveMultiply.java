package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

public class PrimitiveMultiply {

  @EpiTest(testDataFile = "primitive_multiply.tsv")
  public static long multiply(long x, long y) {

    long sum = 0;
    while (x != 0) {
      // Examines each bit of x.
      if ((x & 1) != 0) {
        sum = add(sum, y);
      }
      x >>>= 1;
      y <<= 1;
    }
    return sum;
  }

  private static long add(long a, long b) {
    while (b != 0) {
      long carry = a & b;
      a = a ^ b;
      b = carry << 1;
    }
    return a;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "PrimitiveMultiply.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
