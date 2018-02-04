#include <stdexcept>
#include <vector>

#include "test_framework/test_timer.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::vector;

struct GraphVertex {
  vector<GraphVertex*> edges;
  // Set max_distance = 0 to indicate unvisited vertex.
  int max_distance = 0;
};

int FindLargestNumberTeams(vector<GraphVertex>* graph) {
  // Implement this placeholder.
  return 0;
}

struct Edge {
  int from;
  int to;
};

template <>
struct SerializationTraits<Edge> : UserSerTraits<Edge, int, int> {};

int FindLargestNumberTeamsWrapper(TestTimer& timer, int k,
                                  const vector<Edge>& edges) {
  if (k <= 0) {
    throw std::runtime_error("Invalid k value");
  }

  vector<GraphVertex> graph(k, GraphVertex{});

  for (const Edge& e : edges) {
    if (e.from < 0 || e.from >= k || e.to < 0 || e.to >= k) {
      throw std::runtime_error("Invalid vertex index");
    }
    graph[e.from].edges.push_back(&graph[e.to]);
  }

  timer.Start();
  int result = FindLargestNumberTeams(&graph);
  timer.Stop();
  return result;
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"timer", "k", "edges"};
  GenericTestMain(args, "max_teams_in_photograph.tsv",
                  &FindLargestNumberTeamsWrapper, DefaultComparator{},
                  param_names);
  return 0;
}
