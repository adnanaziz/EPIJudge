package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.List;
import java.util.SortedSet;
import java.util.TreeSet;

// These numbers have very interesting property, and people called it ugly
// numbers. It is also called Quadratic integer rings.

public class ABSqrt2 {

  public static class Number {
    public int a, b;
    public double val;

    public Number(int a, int b) {
      this.a = a;
      this.b = b;
      val = a + b * Math.sqrt(2);
    }
  }

  @EpiTest(testDataFile = "a_b_sqrt2.tsv")

  public static List<Double> generateFirstKABSqrt2(int k) {

    SortedSet<Number> candidates =
        new TreeSet<>((a, b) -> Double.compare(a.val, b.val));
    // Initial for 0 + 0 * sqrt(2).
    candidates.add(new Number(0, 0));

    List<Double> result = new ArrayList<>();
    while (result.size() < k) {
      Number nextSmallest = candidates.first();
      result.add(nextSmallest.val);

      // Add the next two numbers derived from nextSmallest.
      candidates.add(new Number(nextSmallest.a + 1, nextSmallest.b));
      candidates.add(new Number(nextSmallest.a, nextSmallest.b + 1));
      candidates.remove(nextSmallest);
    }
    return result;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "ABSqrt2.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
