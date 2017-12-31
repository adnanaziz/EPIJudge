package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestTimer;

import java.util.ArrayList;
import java.util.List;

public class DeadlockDetection {

  public static class GraphVertex {
    public enum Color { WHITE, GRAY, BLACK }

    public Color color;
    public List<GraphVertex> edges;

    public GraphVertex() {
      color = Color.WHITE;
      edges = new ArrayList<>();
    }
  }

  public static boolean isDeadlocked(List<GraphVertex> G) {
    // Implement this placeholder.
    return true;
  }

  @EpiUserType(ctorParams = {int.class, int.class})
  public static class Edge {
    public int from;
    public int to;

    public Edge(int from, int to) {
      this.from = from;
      this.to = to;
    }
  }

  @EpiTest(testfile = "deadlock_detection.tsv")
  public static boolean isDeadlockedWrapper(TestTimer timer, int k,
                                            List<Edge> edges) {
    if (k <= 0) {
      throw new RuntimeException("Invalid k value");
    }
    List<GraphVertex> graph = new ArrayList<>();
    for (int i = 0; i < k; i++) {
      graph.add(new GraphVertex());
    }
    for (Edge e : edges) {
      if (e.from < 0 || e.from >= k || e.to < 0 || e.to >= k) {
        throw new RuntimeException("Invalid vertex index");
      }
      graph.get(e.from).edges.add(graph.get(e.to));
    }

    timer.start();
    boolean result = isDeadlocked(graph);
    timer.stop();
    return result;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
