package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class BuyAndSellStockTwice {
  @EpiTest(testfile = "buy_and_sell_stock_twice.tsv")
  public static double buyAndSellStockTwice(List<Double> prices) {
    // Implement this placeholder.
    return 0.0;
  }

  public static void main(String[] args) {
    System.exit(GenericTest
                    .runFromAnnotations(
                        args, new Object() {}.getClass().getEnclosingClass())
                    .ordinal());
  }
}
