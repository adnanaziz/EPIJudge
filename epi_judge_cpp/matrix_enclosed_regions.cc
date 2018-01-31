#include <stdexcept>
#include <string>
#include <vector>

#include "test_framework/test_timer.h"

using std::string;
using std::vector;

void FillSurroundedRegions(vector<vector<char>>* board_ptr) {
  // Implement this placeholder.
  return;
}

vector<vector<string>> FillSurroundedRegionsWrapper(
    TestTimer& timer, vector<vector<string>> board) {
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

  timer.Start();
  FillSurroundedRegions(&char_vector);
  timer.Stop();

  board.clear();
  board.resize(char_vector.size(), {});
  for (int i = 0; i < board.size(); i++) {
    for (char c : char_vector[i]) {
      board[i].emplace_back(1, c);
    }
  }

  return board;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"timer", "board"};
  generic_test_main(argc, argv, param_names, "matrix_enclosed_regions.tsv",
                    &FillSurroundedRegionsWrapper);
  return 0;
}
