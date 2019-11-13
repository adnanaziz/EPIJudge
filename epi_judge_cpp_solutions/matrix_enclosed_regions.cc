#include <deque>
#include <queue>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"

using std::deque;
using std::pair;
using std::queue;
using std::string;
using std::vector;

void MarkBoundaryRegion(int, int, vector<vector<char>>*);

void FillSurroundedRegions(vector<vector<char>>* board_ptr) {
  vector<vector<char>>& board = *board_ptr;
  // Identifies the regions that are reachable via white path starting from
  // the first or last columns.
  for (int i = 0; i < size(board); ++i) {
    MarkBoundaryRegion(i, /*j=*/0, board_ptr);
    MarkBoundaryRegion(i, size(board[i]) - 1, board_ptr);
  }
  // Identifies the regions that are reachable via white path starting from
  // the first or last rows.
  for (int j = 0; j < size(board.front()); ++j) {
    MarkBoundaryRegion(/*i=*/0, j, board_ptr);
    MarkBoundaryRegion(size(board) - 1, j, board_ptr);
  }

  // Marks the surrounded white regions as black.
  for (vector<char>& row : board) {
    for (char& c : row) {
      c = c != 'T' ? 'B' : 'W';
    }
  }
}

void MarkBoundaryRegion(int i, int j, vector<vector<char>>* board_ptr) {
  queue<pair<int, int>> q(deque<pair<int, int>>(1, {i, j}));
  vector<vector<char>>& board = *board_ptr;
  // Uses BFS to traverse this region.
  while (!empty(q)) {
    const auto [x, y] = q.front();
    q.pop();
    if (x >= 0 && x < size(board) && y >= 0 && y < size(board[x]) &&
        board[x][y] == 'W') {
      board[x][y] = 'T';
      q.emplace(x - 1, y);
      q.emplace(x + 1, y);
      q.emplace(x, y + 1);
      q.emplace(x, y - 1);
    }
  }
}

vector<vector<string>> FillSurroundedRegionsWrapper(
    TimedExecutor& executor, vector<vector<string>> board) {
  vector<vector<char>> char_vector;
  char_vector.resize(board.size());
  for (int i = 0; i < board.size(); i++) {
    for (const string& s : board[i]) {
      if (s.size() != 1) {
        throw std::runtime_error("String size is not 1");
      }
      char_vector[i].push_back(s[0]);
    }
  }

  executor.Run([&] { FillSurroundedRegions(&char_vector); });

  board.clear();
  board.resize(char_vector.size(), {});
  for (int i = 0; i < board.size(); i++) {
    for (char c : char_vector[i]) {
      board[i].emplace_back(1, c);
    }
  }

  return board;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "board"};
  return GenericTestMain(
      args, "matrix_enclosed_regions.cc", "matrix_enclosed_regions.tsv",
      &FillSurroundedRegionsWrapper, DefaultComparator{}, param_names);
}
