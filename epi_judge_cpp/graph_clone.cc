#include <algorithm>
#include <queue>
#include <unordered_set>
#include <vector>

#include "test_framework/test_failure_exception.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::queue;
using std::unordered_set;
using std::vector;

struct GraphVertex {
  int label;
  vector<GraphVertex*> edges;
};

GraphVertex* CloneGraph(GraphVertex* G) {
  // Implement this placeholder.
  return nullptr;
}

vector<int> CopyLabels(const vector<GraphVertex*>& edges) {
  vector<int> labels;
  transform(begin(edges), end(edges), back_inserter(labels),
            [](const auto& e) { return e->label; });
  return labels;
}

void CheckAndDeallocateGraph(GraphVertex* node, const vector<GraphVertex>& G) {
  if (node == &G[0]) {
    throw TestFailureException("Graph was not copied");
  }

  unordered_set<GraphVertex*> vertex_set;
  queue<GraphVertex*> q;
  q.emplace(node);
  vertex_set.emplace(node);
  while (!q.empty()) {
    auto vertex = q.front();
    q.pop();
    if (vertex->label > G.size()) {
      throw TestFailureException("Invalid vertex label");
    }
    vector<int> label1 = CopyLabels(vertex->edges),
                label2 = CopyLabels(G[vertex->label].edges);
    sort(begin(label1), end(label1)), sort(begin(label2), end(label2));
    if (label1 != label2) {
      throw TestFailureException("Invalid vertex label");
    }
    for (GraphVertex* e : vertex->edges) {
      if (!vertex_set.count(e)) {
        vertex_set.emplace(e);
        q.emplace(e);
      }
    }
  }
  for (auto& v : vertex_set) {
    delete v;
  }
}

struct Edge {
  int from;
  int to;
};

template <>
struct SerializationTraits<Edge> : UserSerTraits<Edge, int, int> {};

void CloneGraphTest(int k, const vector<Edge>& edges) {
  vector<GraphVertex> g;
  if (k <= 0) {
    throw std::runtime_error("Invalid k value");
  }
  g.reserve(k);

  for (int i = 0; i < k; i++) {
    g.push_back(GraphVertex{i});
  }

  for (auto& e : edges) {
    if (e.from < 0 || e.from >= k || e.to < 0 || e.to >= k) {
      throw std::runtime_error("Invalid vertex index");
    }
    g[e.from].edges.push_back(&g[e.to]);
  }
  auto result = CloneGraph(&g[0]);
  CheckAndDeallocateGraph(result, g);
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "graph_clone.tsv", &CloneGraphTest);
  return 0;
}
