package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class BinomialCoefficients {
  @EpiTest(testDataFile = "binomial_coefficients.tsv")

  public static int computeBinomialCoefficient(int n, int k) {

    return computeXChooseY(n, k, new int[n + 1][k + 1]);
  }

  private static int computeXChooseY(int x, int y, int[][] xChooseY) {
    if (y == 0 || x == y) {
      return 1;
    }

    if (xChooseY[x][y] == 0) {
      int withoutY = computeXChooseY(x - 1, y, xChooseY);
      int withY = computeXChooseY(x - 1, y - 1, xChooseY);
      xChooseY[x][y] = withoutY + withY;
    }
    return xChooseY[x][y];
  }

  private static int computeBinomialCoefficientsSpaceEfficient(int n, int k) {
    k = Math.min(k, n - k);
    List<Integer> table = new ArrayList<>(Collections.nCopies(k + 1, 0));
    table.set(0, 1); // C(0, 0).
    // C(i, j) = C(i - 1, j) + C(i - 1, j - 1).
    for (int i = 1; i <= n; ++i) {
      for (int j = Math.min(i, k); j >= 1; --j) {
        table.set(j, table.get(j) + table.get(j - 1));
      }
    }
    return table.get(k);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "BinomialCoefficients.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
