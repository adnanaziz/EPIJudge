package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
public class BuyAndSellStockKTimes {
  @EpiTest(testDataFile = "buy_and_sell_stock_k_times.tsv")

  public static double buyAndSellStockKTimes(List<Double> prices, int k) {
    // TODO - you fill in here.
    return 0.0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "BuyAndSellStockKTimes.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
