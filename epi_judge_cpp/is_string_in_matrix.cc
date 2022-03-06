#include <vector>
#include <unordered_set>
#include "test_framework/generic_test.h"
using std::vector;


struct HashTuple {
    size_t operator()(const std::tuple <int, int, int>& t) const{
        return std::hash<int>()(std::get<0>(t) ^ std::get<1>(t) * 1021 ^ std::get<2>(t) * 1048573);
    }
};


bool IsPatternSubstringContainedInGrid(const vector<vector<int>>& grid,
    const vector<int>& pattern, int x, int y, int offset, 
    std::unordered_set<std::tuple<int, int, int>, HashTuple>& previous_attempts) {
    if (offset == pattern.size())
        return true;

    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[x].size() || 
        previous_attempts.find({ x, y, offset }) != previous_attempts.cend()) {
        return false;
    }

    if (grid[x][y] == pattern[offset] &&
        (IsPatternSubstringContainedInGrid(grid, pattern, x - 1, y, offset + 1, previous_attempts) ||
        IsPatternSubstringContainedInGrid(grid, pattern, x + 1, y, offset + 1, previous_attempts) ||
        IsPatternSubstringContainedInGrid(grid, pattern, x, y - 1, offset + 1, previous_attempts) ||
        IsPatternSubstringContainedInGrid(grid, pattern, x, y + 1, offset + 1, previous_attempts)))
    {
        return true;
    }

    previous_attempts.emplace(x, y, offset);
    return false;

}
bool IsPatternContainedInGrid(const vector<vector<int>>& grid,
                              const vector<int>& pattern) {
    std::unordered_set<std::tuple<int, int, int>, HashTuple> previous_attempts;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[i].size(); j++)
            if (IsPatternSubstringContainedInGrid(grid, pattern, i, j, 0, previous_attempts))
                return true;
    return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"grid", "pattern"};
  return GenericTestMain(args, "is_string_in_matrix.cc",
                         "is_string_in_matrix.tsv", &IsPatternContainedInGrid,
                         DefaultComparator{}, param_names);
}
