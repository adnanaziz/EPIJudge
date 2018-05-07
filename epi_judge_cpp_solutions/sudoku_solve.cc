#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::begin;
using std::end;
using std::vector;

bool SolvePartialSudoku(int, int, vector<vector<int>>*);
bool ValidToAddVal(const vector<vector<int>>&, int, int, int);

const int kEmptyEntry = 0;

bool SolveSudoku(vector<vector<int>>* partial_assignment) {
  return SolvePartialSudoku(0, 0, partial_assignment);
}

bool SolvePartialSudoku(int i, int j, vector<vector<int>>* partial_assignment) {
  if (i == size(*partial_assignment)) {
    i = 0;  // Starts a new row.
    if (++j == size((*partial_assignment)[i])) {
      return true;  // Entire matrix has been filled without conflict.
    }
  }

  // Skips nonempty entries.
  if ((*partial_assignment)[i][j] != kEmptyEntry) {
    return SolvePartialSudoku(i + 1, j, partial_assignment);
  }

  for (int val = 1; val <= size(*partial_assignment); ++val) {
    // It's substantially quicker to check if entry val conflicts
    // with any of the constraints if we add it at (i,j) before
    // adding it, rather than adding it and then checking all constraints.
    // The reason is that we know we are starting with a valid configuration,
    // and the only entry which can cause a problem is entry val at (i,j).
    if (ValidToAddVal(*partial_assignment, i, j, val)) {
      (*partial_assignment)[i][j] = val;
      if (SolvePartialSudoku(i + 1, j, partial_assignment)) {
        return true;
      }
    }
  }

  (*partial_assignment)[i][j] = kEmptyEntry;  // Undo assignment.
  return false;
}

bool ValidToAddVal(const vector<vector<int>>& partial_assignment, int i, int j,
                   int val) {
  // Check row constraints.
  if (any_of(begin(partial_assignment), end(partial_assignment),
             [val, j](const vector<int>& row) { return val == row[j]; })) {
    return false;
  }

  // Check column constraints.
  if (find(begin(partial_assignment[i]), end(partial_assignment[i]), val) !=
      end(partial_assignment[i])) {
    return false;
  }

  // Check region constraints.
  int region_size = sqrt(size(partial_assignment));
  int I = i / region_size, J = j / region_size;
  for (int a = 0; a < region_size; ++a) {
    for (int b = 0; b < region_size; ++b) {
      if (val == partial_assignment[region_size * I + a][region_size * J + b]) {
        return false;
      }
    }
  }
  return true;
}

vector<int> GatherColumn(const vector<vector<int>>& data, size_t i) {
  vector<int> result;
  for (auto& row : data) {
    result.push_back(row[i]);
  }
  return result;
}

vector<int> GatherSquareBlock(const vector<vector<int>>& data,
                              size_t block_size, size_t n) {
  vector<int> result;
  size_t block_x = n % block_size;
  size_t block_y = n / block_size;
  for (size_t i = block_x * block_size; i < (block_x + 1) * block_size; i++) {
    for (size_t j = block_y * block_size; j < (block_y + 1) * block_size; j++) {
      result.push_back(data[i][j]);
    }
  }

  return result;
}

void AssertUniqueSeq(const vector<int>& seq) {
  vector<bool> seen(seq.size(), false);
  for (auto& x : seq) {
    if (x == 0) {
      throw TestFailure("Cell left uninitialized");
    }
    if (x < 0 || x > seq.size()) {
      throw TestFailure("Cell value out of range");
    }
    if (seen[x - 1]) {
      throw TestFailure("Duplicate value in section");
    }
    seen[x - 1] = true;
  }
}

void SolveSudokuWrapper(TimedExecutor& executor,
                        const vector<vector<int>>& partial_assignment) {
  vector<vector<int>> solved = partial_assignment;

  executor.Run([&] { SolveSudoku(&solved); });

  if (!std::equal(begin(partial_assignment), end(partial_assignment),
                  begin(solved), end(solved), [](auto br, auto cr) {
                    return std::equal(begin(br), end(br), begin(cr), end(cr),
                                      [](int bcell, int ccell) {
                                        return bcell == 0 || bcell == ccell;
                                      });
                  }))
    throw TestFailure("Initial cell assignment has been changed");

  auto block_size = static_cast<size_t>(sqrt(solved.size()));

  for (size_t i = 0; i < solved.size(); i++) {
    AssertUniqueSeq(solved[i]);
    AssertUniqueSeq(GatherColumn(solved, i));
    AssertUniqueSeq(GatherSquareBlock(solved, block_size, i));
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "partial_assignment"};
  return GenericTestMain(args, "sudoku_solve.cc", "sudoku_solve.tsv",
                         &SolveSudokuWrapper, DefaultComparator{}, param_names);
}
