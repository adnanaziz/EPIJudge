package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTest;
import epi.test_framework.TimedExecutor;

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

  public static boolean isDeadlocked(List<GraphVertex> graph) {

    return graph.stream().anyMatch(
        vertex -> vertex.color == GraphVertex.Color.WHITE && hasCycle(vertex));
  }

  private static boolean hasCycle(GraphVertex cur) {
    // Visiting a gray vertex means a cycle.
    if (cur.color == GraphVertex.Color.GRAY) {
      return true;
    }

    cur.color = GraphVertex.Color.GRAY; // Marks current vertex as a gray one.
    // Traverse the neighbor vertices.
    if (cur.edges.stream().anyMatch(
            next -> next.color != GraphVertex.Color.BLACK && hasCycle(next))) {
      return true;
    }
    cur.color = GraphVertex.Color.BLACK; // Marks current vertex as black.
    return false;
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

  @EpiTest(testDataFile = "deadlock_detection.tsv")
  public static boolean isDeadlockedWrapper(TimedExecutor executor,
                                            int numNodes, List<Edge> edges)
      throws Exception {
    if (numNodes <= 0) {
      throw new RuntimeException("Invalid numNodes value");
    }
    List<GraphVertex> graph = new ArrayList<>();
    for (int i = 0; i < numNodes; i++) {
      graph.add(new GraphVertex());
    }
    for (Edge e : edges) {
      if (e.from < 0 || e.from >= numNodes || e.to < 0 || e.to >= numNodes) {
        throw new RuntimeException("Invalid vertex index");
      }
      graph.get(e.from).edges.add(graph.get(e.to));
    }

    return executor.run(() -> isDeadlocked(graph));
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "DeadlockDetection.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
