#include <algorithm>
#include <memory>
#include <stack>
#include <stdexcept>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/timed_executor.h"

using std::make_unique;
using std::max;
using std::vector;

struct GraphVertex;
int Dfs(GraphVertex* curr);

struct GraphVertex {
  vector<GraphVertex*> edges;
  // Set max_distance = 0 to indicate unvisited vertex.
  int max_distance = 0;
};

int FindLargestNumberTeams(vector<GraphVertex>* graph) {
  int max_level = 0;
  for (GraphVertex& g : *graph) {
    if (g.max_distance == 0) {
      max_level = max(max_level, Dfs(&g));
    }
  }
  return max_level;
}

int Dfs(GraphVertex* curr) {
  curr->max_distance = 1;
  for (GraphVertex* vertex : curr->edges) {
    curr->max_distance =
        max(curr->max_distance,
            (vertex->max_distance ? vertex->max_distance : Dfs(vertex)) + 1);
  }
  return curr->max_distance;
}

struct Edge {
  int from;
  int to;
};

namespace test_framework {
template <>
struct SerializationTrait<Edge> : UserSerTrait<Edge, int, int> {};
}  // namespace test_framework

int FindLargestNumberTeamsWrapper(TimedExecutor& executor, int k,
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

  return executor.Run([&] { return FindLargestNumberTeams(&graph); });
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "k", "edges"};
  return GenericTestMain(
      args, "max_teams_in_photograph.cc", "max_teams_in_photograph.tsv",
      &FindLargestNumberTeamsWrapper, DefaultComparator{}, param_names);
}
