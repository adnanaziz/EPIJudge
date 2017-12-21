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
    TestTimer& timer, vector<vector<string>> raw) {
  vector<vector<char>> char_vector;
  char_vector.resize(raw.size());
  for (size_t i = 0; i < raw.size(); i++) {
    for (auto& s : raw[i]) {
      if (s.size() != 1) {
        throw std::runtime_error("String size is not 1");
      }
      char_vector[i].push_back(s[0]);
    }
  }

  timer.Start();
  FillSurroundedRegions(&char_vector);
  timer.Stop();

  raw.clear();
  raw.resize(char_vector.size(), {});
  for (size_t i = 0; i < raw.size(); i++) {
    for (auto c : char_vector[i]) {
      raw[i].emplace_back(1, c);
    }
  }

  return raw;
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "matrix_enclosed_regions.tsv",
                    &FillSurroundedRegionsWrapper);
  return 0;
}
