package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTestHandler;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Queue;
import java.util.Set;

public class GraphClone {

  public static class GraphVertex {
    public int label;
    public List<GraphVertex> edges;

    public GraphVertex(int label) {
      this.label = label;
      edges = new ArrayList<>();
    }
  }

  public static GraphVertex cloneGraph(GraphVertex g) {
    // Implement this placeholder.
    return null;
  }

  private static List<Integer> copyLabels(List<GraphVertex> edges) {
    List<Integer> labels = new ArrayList<>();
    for (GraphVertex e : edges) {
      labels.add(e.label);
    }
    return labels;
  }

  private static void checkGraph(GraphVertex node, List<GraphVertex> g) {
    Set<GraphVertex> vertexSet = new HashSet<>();
    Queue<GraphVertex> q = new ArrayDeque<>();
    q.add(node);
    vertexSet.add(node);
    while (!q.isEmpty()) {
      GraphVertex vertex = q.remove();
      assert(vertex.label < g.size());
      List<Integer> label1 = copyLabels(vertex.edges),
                    label2 = copyLabels(g.get(vertex.label).edges);
      Collections.sort(label1);
      Collections.sort(label2);
      assert(label1.size() == label2.size());
      assert(Arrays.equals(label1.toArray(), label2.toArray()));
      for (GraphVertex e : vertex.edges) {
        if (!vertexSet.contains(e)) {
          vertexSet.add(e);
          q.add(e);
        }
      }
    }
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

  @EpiTest(testfile = "graph_clone.tsv")
  public static void cloneGraphTest(int k, List<Edge> edges) {
    if (k <= 0) {
      throw new RuntimeException("Invalid k value");
    }
    List<GraphVertex> graph = new ArrayList<>();
    for (int i = 0; i < k; i++) {
      graph.add(new GraphVertex(i));
    }
    for (Edge e : edges) {
      if (e.from < 0 || e.from >= k || e.to < 0 || e.to >= k) {
        throw new RuntimeException("Invalid vertex index");
      }
      graph.get(e.from).edges.add(graph.get(e.to));
    }
    GraphVertex result = cloneGraph(graph.get(0));
    checkGraph(result, graph);
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
