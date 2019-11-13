package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.HashMap;
import java.util.Map;

public class Fibonacci {

  private static Map<Integer, Integer> cache = new HashMap<>();

  @EpiTest(testDataFile = "fibonacci.tsv")

  public static int fibonacci(int n) {

    if (n <= 1) {
      return n;
    }
    cache.putIfAbsent(n, fibonacci(n - 2) + fibonacci(n - 1));
    return cache.get(n);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "Fibonacci.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
