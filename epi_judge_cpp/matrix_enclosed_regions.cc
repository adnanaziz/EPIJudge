#include <stdexcept>
#include <string>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::string;
using std::vector;

void MakeBoundryRegion(int i, int j, vector<vector<char>>& board,
    vector<std::deque<bool>>& visited) {
    struct Coordinate {
        int x, y;
    };

    std::queue<Coordinate> q;
    q.push(Coordinate{ i, j });
    visited[i][j] = true;


    std::array<std::array<int, 2>, 4> adjacent{ {{0,1}, {0,-1}, {1,0}, {-1,0}} };
    while(!q.empty()){
        Coordinate curr = q.front();
        for (const std::array<int, 2>& d : adjacent) {
            Coordinate next = Coordinate{ curr.x + d[0], curr.y + d[1] };
            if (next.x >= 0 && next.x < board.size() &&
                next.y >= 0 && next.y < board[next.x].size() &&
                board[next.x][next.y] == 'W' && !visited[next.x][next.y]) {
                visited[next.x][next.y] = true;
                q.push(next);
            }
        }
        q.pop();
    }
}

void FillSurroundedRegions(vector<vector<char>>* board_ptr) {
    vector<vector<char>>& board = *board_ptr;
    
    vector<std::deque<bool>> visited(board.size(), std::deque<bool>(board.front().size(), false));
    
    for (int i = 0; i < board.size(); i++) {
        if (board[i][0] == 'W' && !visited[i][0]) {
            MakeBoundryRegion(i, 0, board, visited);
        }

        if (board[i][board.front().size()-1] == 'W' && !visited[i][board.front().size() - 1]) {
            MakeBoundryRegion(i, board.front().size() - 1, board, visited);
        }
    }

    for (int j = 0; j < board.front().size(); j++) {
        if (board[0][j] == 'W' && !visited[0][j]) {
            MakeBoundryRegion(0, j, board, visited);
        }

        if (board[board.size()-1][j] == 'W' && !visited[board.size() - 1] [j] ) {
            MakeBoundryRegion(board.size() - 1, j, board, visited);
        }
    }

    for (int i = 1; i < board.size()-1; i++) {
        for (int j = 1; j < board.front().size()-1; j++) {
            if (board[i][j] == 'W' && !visited[i][j]) {
                board[i][j] = 'B';
            }
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
