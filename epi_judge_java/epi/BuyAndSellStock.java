package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTestHandler;

import java.util.List;

public class BuyAndSellStock {
  @EpiTest(testfile = "buy_and_sell_stock.tsv")
  public static double computeMaxProfit(List<Double> prices) {
    // Implement this placeholder.
    return 0.0;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
