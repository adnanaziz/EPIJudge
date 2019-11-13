package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;
import epi.test_framework.TimedExecutor;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class IsCircuitWirable {

  public static class GraphVertex {
    public int d = -1;
    public List<GraphVertex> edges = new ArrayList<>();
  }

  public static boolean isAnyPlacementFeasible(List<GraphVertex> graph) {

    return graph.stream().allMatch(v -> v.d != -1 || bfs(v));
  }

  private static boolean bfs(GraphVertex s) {
    s.d = 0;
    Queue<GraphVertex> q = new ArrayDeque<>();
    q.add(s);

    while (!q.isEmpty()) {
      for (GraphVertex t : q.peek().edges) {
        if (t.d == -1) { // Unvisited vertex.
          t.d = q.peek().d + 1;
          q.add(t);
        } else if (t.d == q.peek().d) {
          return false;
        }
      }
      q.remove();
    }
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

  @EpiTest(testDataFile = "is_circuit_wirable.tsv")
  public static boolean isAnyPlacementFeasibleWrapper(TimedExecutor executor,
                                                      int k, List<Edge> edges)
      throws Exception {
    if (k <= 0)
      throw new RuntimeException("Invalid k value");
    List<GraphVertex> graph = new ArrayList<>();
    for (int i = 0; i < k; i++)
      graph.add(new GraphVertex());
    for (Edge e : edges) {
      if (e.from < 0 || e.from >= k || e.to < 0 || e.to >= k)
        throw new RuntimeException("Invalid vertex index");
      graph.get(e.from).edges.add(graph.get(e.to));
    }

    return executor.run(() -> isAnyPlacementFeasible(graph));
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "IsCircuitWirable.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
