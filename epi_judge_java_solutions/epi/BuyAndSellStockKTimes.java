package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class BuyAndSellStockKTimes {
  @EpiTest(testDataFile = "buy_and_sell_stock_k_times.tsv")

  public static double buyAndSellStockKTimes(List<Double> prices, int k) {

    if (k == 0) {
      return 0.0;
    } else if (2 * k >= prices.size()) {
      return unlimitedPairsProfits(prices);
    }
    List<Double> minPrices =
                     new ArrayList<>(Collections.nCopies(k, Double.MAX_VALUE)),
                 maxProfits = new ArrayList<>(Collections.nCopies(k, 0.0));
    for (Double price : prices) {
      for (int i = k - 1; i >= 0; --i) {
        maxProfits.set(i,
                       Math.max(maxProfits.get(i), price - minPrices.get(i)));
        minPrices.set(i,
                      Math.min(minPrices.get(i),
                               price - (i > 0 ? maxProfits.get(i - 1) : 0.0)));
      }
    }
    return maxProfits.get(maxProfits.size() - 1);
  }

  private static double unlimitedPairsProfits(List<Double> prices) {
    double profit = 0.0;
    for (int i = 1; i < prices.size(); ++i) {
      profit += Math.max(0.0, prices.get(i) - prices.get(i - 1));
    }
    return profit;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "BuyAndSellStockKTimes.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
