#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

#include "test_framework/generic_test.h"

using std::numeric_limits;
using std::vector;

bool BellmanFord(const vector<vector<double>>& graph, int source);

bool IsArbitrageExist(vector<vector<double>> graph) {
  // Transforms each edge in graph.
  for_each(begin(graph), end(graph), [](vector<double>& edge_list) {
    for_each(begin(edge_list), end(edge_list),
             [](double& edge) { edge = -log10(edge); });
  });

  // Uses Bellman-Ford to find negative weight cycle.
  return BellmanFord(graph, 0);
}

bool BellmanFord(const vector<vector<double>>& graph, int source) {
  vector<double> dis_to_source(size(graph), numeric_limits<double>::infinity());
  dis_to_source[source] = 0;

  for (int times = 1; times < size(graph); ++times) {
    bool have_update = false;
    for (int i = 0; i < size(graph); ++i) {
      for (int j = 0; j < size(graph[i]); ++j) {
        if (dis_to_source[i] != numeric_limits<double>::infinity() &&
            dis_to_source[j] > dis_to_source[i] + graph[i][j]) {
          have_update = true;
          dis_to_source[j] = dis_to_source[i] + graph[i][j];
        }
      }
    }

    // No update in this iteration means no negative cycle.
    if (have_update == false) {
      return false;
    }
  }

  // Detects cycle if there is any further update.
  for (int i = 0; i < size(graph); ++i) {
    for (int j = 0; j < size(graph[i]); ++j) {
      if (dis_to_source[i] != numeric_limits<double>::infinity() &&
          dis_to_source[j] > dis_to_source[i] + graph[i][j]) {
        return true;
      }
    }
  }
  return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"graph"};
  return GenericTestMain(args, "arbitrage.cc", "arbitrage.tsv",
                         &IsArbitrageExist, DefaultComparator{}, param_names);
}
