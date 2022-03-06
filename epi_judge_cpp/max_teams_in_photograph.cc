#include <stdexcept>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/timed_executor.h"
using std::vector;

struct GraphVertex {
  vector<GraphVertex*> edges;
  // Set max_distance = 0 to indicate unvisited vertex.
  int max_distance = 0;
};

void DFS(GraphVertex* cur, std::stack<GraphVertex*>* topo_order) {
    cur->max_distance = 1;
    for (GraphVertex* next : cur->edges) {
        if (next->max_distance == 0) {
            DFS(next, topo_order);
        }
    }
    topo_order->push(cur);

}

std::stack<GraphVertex*> BuildTopologicalOrder(vector<GraphVertex>* graph) {
    std::stack<GraphVertex*> topo_order;
    
    for(auto& g : *graph) {
        if (g.max_distance == 0) {
           DFS(&g, &topo_order);
        }
    }
    return topo_order;
}

int CalculateLargestNumberOfTeams(std::stack<GraphVertex*>* topo_order){
    int max_distance = 0;

    while (!topo_order->empty()) {
        GraphVertex* u = topo_order->top();
        max_distance = std::max(max_distance, u->max_distance);
        for(GraphVertex* v : u->edges) {
            v->max_distance = std::max(v->max_distance, u->max_distance + 1);
        }
        topo_order->pop();
    }

    return max_distance;
}

int FindLargestNumberTeams(vector<GraphVertex>* graph) {
    std::stack<GraphVertex*> topo_order(BuildTopologicalOrder(graph));
    return CalculateLargestNumberOfTeams(&topo_order);
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
