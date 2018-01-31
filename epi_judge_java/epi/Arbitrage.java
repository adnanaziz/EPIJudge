package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

import java.util.List;

public class Arbitrage {
  @EpiTest(testfile = "arbitrage.tsv")

  public static boolean isArbitrageExist(List<List<Double>> graph) {
    // Implement this placeholder.
    return true;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
