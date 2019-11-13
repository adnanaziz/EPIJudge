package epi;
import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;
public class PickingUpCoins {
  @EpiTest(testDataFile = "picking_up_coins.tsv")

  public static int pickUpCoins(List<Integer> coins) {
    // TODO - you fill in here.
    return 0;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "PickingUpCoins.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
