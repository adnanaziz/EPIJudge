package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class NumberOfTraversalsMatrix {
  @EpiTest(testDataFile = "number_of_traversals_matrix.tsv")

  public static int numberOfWays(int n, int m) {

    return computeNumberOfWaysToXY(n - 1, m - 1, new int[n][m]);
  }

  private static int computeNumberOfWaysToXY(int x, int y,
                                             int[][] numberOfWays) {
    if (x == 0 && y == 0) {
      return 1;
    }

    if (numberOfWays[x][y] == 0) {
      int waysTop =
          x == 0 ? 0 : computeNumberOfWaysToXY(x - 1, y, numberOfWays);
      int waysLeft =
          y == 0 ? 0 : computeNumberOfWaysToXY(x, y - 1, numberOfWays);
      numberOfWays[x][y] = waysTop + waysLeft;
    }
    return numberOfWays[x][y];
  }

  private static int numberOfWaysSpaceEfficient(int n, int m) {
    if (n < m) {
      int temp = n;
      n = m;
      m = temp;
    }

    List<Integer> table = new ArrayList<>(Collections.nCopies(m, 1));
    for (int i = 1; i < n; ++i) {
      int prevRes = 0;
      for (int j = 0; j < m; ++j) {
        table.set(j, table.get(j) + prevRes);
        prevRes = table.get(j);
      }
    }
    return table.get(m - 1);
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "NumberOfTraversalsMatrix.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
