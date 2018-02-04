#include <stdexcept>
#include <vector>

#include "test_framework/test_timer.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::vector;

struct GraphVertex {
  enum Color { white, gray, black } color = white;
  vector<GraphVertex*> edges;
};

bool IsDeadlocked(vector<GraphVertex>* graph) {
  // Implement this placeholder.
  return true;
}

struct Edge {
  int from;
  int to;
};

template <>
struct SerializationTraits<Edge> : UserSerTraits<Edge, int, int> {};

bool HasCycleWrapper(TestTimer& timer, int num_nodes,
                     const vector<Edge>& edges) {
  vector<GraphVertex> graph;
  if (num_nodes <= 0) {
    throw std::runtime_error("Invalid num_nodes value");
  }
  graph.reserve(num_nodes);

  for (int i = 0; i < num_nodes; i++) {
    graph.push_back(GraphVertex{});
  }

  for (const Edge& e : edges) {
    if (e.from < 0 || e.from >= num_nodes || e.to < 0 || e.to >= num_nodes) {
      throw std::runtime_error("Invalid vertex index");
    }
    graph[e.from].edges.push_back(&graph[e.to]);
  }

  timer.Start();
  bool result = IsDeadlocked(&graph);
  timer.Stop();
  return result;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "num_nodes", "edges"};
  GenericTestMain(args, "deadlock_detection.tsv", &HasCycleWrapper,
                  DefaultComparator{}, param_names);
  return 0;
}
