package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class BuyAndSellStock {

  @EpiTest(testDataFile = "buy_and_sell_stock.tsv")
  public static double computeMaxProfit(List<Double> prices) {

    double minPrice = Double.MAX_VALUE, maxProfit = 0.0;
    for (Double price : prices) {
      maxProfit = Math.max(maxProfit, price - minPrice);
      minPrice = Math.min(minPrice, price);
    }
    return maxProfit;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "BuyAndSellStock.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
