package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.List;

public class MatrixEnclosedRegions {

  public static void fillSurroundedRegions(List<List<Character>> board) {
    int m = board.size();
    int n = board.get(0).size();
    // Reach Ws from the enclosing boundary
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if ((i == 0 || i == m-1 || j == 0 || j == n-1)
                && board.get(i).get(j) == 'W') {
          dfs(board, i, j);
        }
      }
    }
    // Iterate through the board and replace 'W's with 'B' and 'D's with 'W'
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board.get(i).get(j) == 'W') {
          board.get(i).set(j, 'B');
        }
        if (board.get(i).get(j) == 'D') {
          board.get(i).set(j, 'W');
        }
      }
    }
    return;
  }

  private static void dfs(List<List<Character>> board, int x, int y) {
    board.get(x).set(y, 'D'); // mark as Done
    final int[][] DIR = new int[][]{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    for (int[] dir : DIR) {
      int newX = dir[0] + x;
      int newY = dir[1] + y;
      if (isValidCoordinate(newX, newY, board.size(), board.get(0).size())
              && board.get(newX).get(newY) == 'W') {
        dfs(board, newX, newY);
      }
    }
  }

  private static boolean isValidCoordinate(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
  }

  @EpiTest(testDataFile = "matrix_enclosed_regions.tsv")
  public static List<List<Character>>
  fillSurroundedRegionsWrapper(List<List<Character>> board) {
    fillSurroundedRegions(board);
    return board;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MatrixEnclosedRegions.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
