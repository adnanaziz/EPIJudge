#include <algorithm>
#include <functional>
#include <numeric>
#include <queue>
#include <vector>

#include "test_framework/generic_test.h"

using std::function;
using std::max;
using std::priority_queue;
using std::vector;

int CalculateBonus(const vector<int>& productivity) {
  struct EmployeeData {
    int productivity, index;
  };
  priority_queue<EmployeeData, vector<EmployeeData>,
                 function<bool(EmployeeData, EmployeeData)>>
      min_heap([](const EmployeeData& a, const EmployeeData& b) {
        return a.productivity > b.productivity;
      });
  for (int i = 0; i < size(productivity); ++i) {
    min_heap.emplace(EmployeeData{productivity[i], i});
  }

  // Initially assigns one ticket to everyone.
  vector<int> tickets(size(productivity), 1);
  // Fills tickets from lowest rating to highest rating.
  while (!empty(min_heap)) {
    int next_dev = min_heap.top().index;
    // Handles the left neighbor.
    if (next_dev > 0 && productivity[next_dev] > productivity[next_dev - 1]) {
      tickets[next_dev] = tickets[next_dev - 1] + 1;
    }
    // Handles the right neighbor.
    if (next_dev + 1 < size(tickets) &&
        productivity[next_dev] > productivity[next_dev + 1]) {
      tickets[next_dev] = max(tickets[next_dev], tickets[next_dev + 1] + 1);
    }
    min_heap.pop();
  }
  return accumulate(begin(tickets), end(tickets), 0);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"productivity"};
  return GenericTestMain(args, "bonus.cc", "bonus.tsv", &CalculateBonus,
                         DefaultComparator{}, param_names);
}
