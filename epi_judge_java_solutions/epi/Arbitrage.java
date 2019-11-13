package epi;

import epi.test_framework.EpiTest;
import epi.test_framework.GenericTest;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Arbitrage {
  @EpiTest(testDataFile = "arbitrage.tsv")

  public static boolean isArbitrageExist(List<List<Double>> graph) {

    // Transforms each edge in graph.
    for (List<Double> edgeList : graph) {
      for (int i = 0; i < edgeList.size(); i++) {
        edgeList.set(i, -Math.log10(edgeList.get(i)));
      }
    }

    // Uses Bellman-Ford to find negative weight cycle.
    return bellmanFord(graph, 0);
  }

  private static boolean bellmanFord(List<List<Double>> graph, int source) {
    List<Double> disToSource =
        new ArrayList<>(Collections.nCopies(graph.size(), Double.MAX_VALUE));
    disToSource.set(source, 0.0);

    for (int times = 1; times < graph.size(); ++times) {
      boolean haveUpdate = false;
      for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph.get(i).size(); ++j) {
          if (disToSource.get(i) != Double.MAX_VALUE &&
              disToSource.get(j) > disToSource.get(i) + graph.get(i).get(j)) {
            haveUpdate = true;
            disToSource.set(j, disToSource.get(i) + graph.get(i).get(j));
          }
        }
      }

      // No update in this iteration means no negative cycle.
      if (!haveUpdate) {
        return false;
      }
    }

    // Detects cycle if there is any further update.
    for (int i = 0; i < graph.size(); ++i) {
      for (int j = 0; j < graph.get(i).size(); ++j) {
        if (disToSource.get(i) != Double.MAX_VALUE &&
            disToSource.get(j) > disToSource.get(i) + graph.get(i).get(j)) {
          return true;
        }
      }
    }
    return false;
  }

  public static void main(String[] args) {
    System.exit(
        GenericTest
            .runFromAnnotations(args, "Arbitrage.java",
                                new Object() {}.getClass().getEnclosingClass())
            .ordinal());
  }
}
