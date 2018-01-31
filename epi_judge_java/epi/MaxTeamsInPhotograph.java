package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.EpiUserType;
import epi.test_framework.GenericTestHandler;
import epi.test_framework.TestTimer;

import java.util.ArrayList;
import java.util.List;

public class MaxTeamsInPhotograph {

  public static class GraphVertex {
    public List<GraphVertex> edges = new ArrayList<>();
    // Set maxDistance = 0 to indicate unvisited vertex.
    public int maxDistance = 0;
  }

  public static int findLargestNumberTeams(List<GraphVertex> graph) {
    // Implement this placeholder.
    return 0;
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

  @EpiTest(testfile = "max_teams_in_photograph.tsv")
  public static int findLargestNumberTeamsWrapper(TestTimer timer, int k,
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
    int result = findLargestNumberTeams(graph);
    timer.stop();
    return result;
  }

  public static void main(String[] args) {
    GenericTestHandler.executeTestsByAnnotation(
        new Object() {}.getClass().getEnclosingClass(), args);
  }
}
