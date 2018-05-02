#include <array>
#include <stack>
#include <string>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::array;
using std::stack;
using std::vector;

void ComputeTowerHanoiSteps(int, array<stack<int>, 3>&, int, int, int,
                            vector<vector<int>>*);

const int kNumPegs = 3;

vector<vector<int>> ComputeTowerHanoi(int num_rings) {
  array<stack<int>, kNumPegs> pegs;
  // Initialize pegs.
  for (int i = num_rings; i >= 1; --i) {
    pegs[0].push(i);
  }

  vector<vector<int>> result;
  ComputeTowerHanoiSteps(num_rings, pegs, 0, 1, 2, &result);
  return result;
}

void ComputeTowerHanoiSteps(int num_rings_to_move,
                            array<stack<int>, kNumPegs>& pegs, int from_peg,
                            int to_peg, int use_peg,
                            vector<vector<int>>* result_ptr) {
  if (num_rings_to_move > 0) {
    ComputeTowerHanoiSteps(num_rings_to_move - 1, pegs, from_peg, use_peg,
                           to_peg, result_ptr);
    pegs[to_peg].push(pegs[from_peg].top());
    pegs[from_peg].pop();
    result_ptr->emplace_back(vector<int>{from_peg, to_peg});
    ComputeTowerHanoiSteps(num_rings_to_move - 1, pegs, use_peg, to_peg,
                           from_peg, result_ptr);
  }
}

void ComputeTowerHanoiWrapper(TimedExecutor& executor, int num_rings) {
  array<stack<int>, kNumPegs> pegs;
  for (int i = num_rings; i >= 1; --i) {
    pegs[0].push(i);
  }

  vector<vector<int>> result =
      executor.Run([&] { return ComputeTowerHanoi(num_rings); });

  for (const vector<int>& operation : result) {
    int from_peg = operation[0], to_peg = operation[1];
    if (!pegs[to_peg].empty() && pegs[from_peg].top() >= pegs[to_peg].top()) {
      throw TestFailure("Illegal move from " +
                        std::to_string(pegs[from_peg].top()) + " to " +
                        std::to_string(pegs[to_peg].top()));
    }
    pegs[to_peg].push(pegs[from_peg].top());
    pegs[from_peg].pop();
  }
  array<stack<int>, kNumPegs> expected_pegs1, expected_pegs2;
  for (int i = num_rings; i >= 1; --i) {
    expected_pegs1[1].push(i);
  }
  for (int i = num_rings; i >= 1; --i) {
    expected_pegs2[2].push(i);
  }
  if (pegs != expected_pegs1 && pegs != expected_pegs2) {
    throw TestFailure("Pegs doesn't place in the right configuration");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "num_rings"};
  return GenericTestMain(args, "hanoi.cc", "hanoi.tsv",
                         &ComputeTowerHanoiWrapper, DefaultComparator{},
                         param_names);
}
