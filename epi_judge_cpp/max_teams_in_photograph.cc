#include <stdexcept>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_utils_serialization_traits.h"
#include "test_framework/timed_executor.h"

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
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "k", "edges"};
  return GenericTestMain(args, timeout_seconds, "max_teams_in_photograph.tsv",
                         &FindLargestNumberTeamsWrapper, DefaultComparator{},
                         param_names);
}
