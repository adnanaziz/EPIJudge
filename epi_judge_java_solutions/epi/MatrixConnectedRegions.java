package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;
import epi.test_framework.TimedExecutor;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class MatrixConnectedRegions {

  private static class Coordinate {
    public Integer x;
    public Integer y;

    public Coordinate(Integer x, Integer y) {
      this.x = x;
      this.y = y;
    }
  }

  public static void flipColor(int x, int y, List<List<Boolean>> image) {

    boolean color = image.get(x).get(y);

    Queue<Coordinate> q = new ArrayDeque<>();
    image.get(x).set(y, !image.get(x).get(y)); // Flips.
    q.add(new Coordinate(x, y));
    while (!q.isEmpty()) {
      Coordinate cur = q.element();
      for (Coordinate nextMove : List.of(new Coordinate(cur.x, cur.y + 1),
                                         new Coordinate(cur.x, cur.y - 1),
                                         new Coordinate(cur.x + 1, cur.y),
                                         new Coordinate(cur.x - 1, cur.y))) {
        if (nextMove.x >= 0 && nextMove.x < image.size() && nextMove.y >= 0 &&
            nextMove.y < image.get(nextMove.x).size() &&
            image.get(nextMove.x).get(nextMove.y) == color) {
          // Flips the color.
          image.get(nextMove.x).set(nextMove.y, !color);
          q.add(nextMove);
        }
      }
      q.remove();
    }
  }

  @EpiTest(testDataFile = "painting.tsv")
  public static List<List<Integer>> flipColorWrapper(TimedExecutor executor,
                                                     int x, int y,
                                                     List<List<Integer>> image)
      throws Exception {
    List<List<Boolean>> B = new ArrayList<>();
    for (int i = 0; i < image.size(); i++) {
      B.add(new ArrayList<>());
      for (int j = 0; j < image.get(i).size(); j++) {
        B.get(i).add(image.get(i).get(j) == 1);
      }
    }

    executor.run(() -> flipColor(x, y, B));

    image = new ArrayList<>();
    for (int i = 0; i < B.size(); i++) {
      image.add(new ArrayList<>());
      for (int j = 0; j < B.get(i).size(); j++) {
        image.get(i).add(B.get(i).get(j) ? 1 : 0);
      }
    }

    return image;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "MatrixConnectedRegions.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
