#include <algorithm>
#include <limits>
#include <vector>

#include "test_framework/fmt_print.h"
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"

using std::max;
using std::min;
using std::numeric_limits;
using std::vector;

void FloydWarshall(vector<vector<int>>* G_ptr);

struct HighwaySection {
  int x, y, distance;
};

HighwaySection FindBestProposals(const vector<HighwaySection>& H,
                                 const vector<HighwaySection>& P, int n) {
  // graph stores the shortest path distances between all pairs of vertices.
  vector<vector<int>> graph(n, vector<int>(n, numeric_limits<int>::max()));
  for (int i = 0; i < n; ++i) {
    graph[i][i] = 0;
  }
  // Builds an undirected graph graph based on existing highway sections H.
  for (const auto& [x, y, distance] : H) {
    graph[x][y] = graph[y][x] = distance;
  }

  // Performs Floyd Warshall to build the shortest path between vertices.
  FloydWarshall(&graph);

  // Examines each proposal for shorter distance for all pairs.
  int best_distance_saving = numeric_limits<int>::min();
  HighwaySection best_proposal = {-1, -1, 0};  // Default.
  for (const auto& [x, y, distance] : P) {
    int proposal_saving = 0;
    for (int a = 0; a < n; ++a) {
      for (int b = 0; b < n; ++b) {
        int saving = graph[a][b] - min(graph[a][x] + distance + graph[y][b],
                                       graph[a][y] + distance + graph[x][b]);
        proposal_saving += max(saving, 0);
      }
    }
    if (proposal_saving > best_distance_saving) {
      best_distance_saving = proposal_saving;
      best_proposal = {x, y, distance};
    }
  }
  return best_proposal;
}

void FloydWarshall(vector<vector<int>>* G_ptr) {
  vector<vector<int>>& graph = *G_ptr;
  for (int k = 0; k < size(graph); ++k) {
    for (int i = 0; i < size(graph); ++i) {
      for (int j = 0; j < size(graph); ++j) {
        if (graph[i][k] != numeric_limits<int>::max() &&
            graph[k][j] != numeric_limits<int>::max()) {
          graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
      }
    }
  }
}

namespace test_framework {
template <>
struct SerializationTrait<HighwaySection>
    : UserSerTrait<HighwaySection, int, int, int> {};
}  // namespace test_framework

bool operator==(const HighwaySection& lhs, const HighwaySection& rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y && lhs.distance == rhs.distance;
}

std::ostream& operator<<(std::ostream& out, const HighwaySection& hs) {
  return PrintTo(out, std::make_tuple(hs.x, hs.y, hs.distance));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"H", "P", "n"};
  return GenericTestMain(args, "road_network.cc", "road_network.tsv",
                         &FindBestProposals, DefaultComparator{}, param_names);
}
