#include <algorithm>
#include <iterator>
#include <vector>

#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::vector;

class Team {
 public:
  explicit Team(const vector<int>& height) {
    transform(begin(height), end(height), back_inserter(players_),
              [](int h) { return Player{h}; });
  }

  // Checks if team0 can be placed in front of team1.
  static bool ValidPlacementExists(const Team& team0, const Team& team1) {
    // Implement this placeholder.
    return true;
  }

 private:
  struct Player {
    bool operator<(const Player& that) const { return height < that.height; }

    int height;
  };

  vector<Player> players_;
};

void ValidPlacementExistsWrapper(TestTimer& timer, const vector<int>& team0,
                                 const vector<int>& team1, bool expected_01,
                                 bool expected_10) {
  Team t0(team0), t1(team1);
  timer.Start();
  if (Team::ValidPlacementExists(t0, t1) != expected_01 &&
      Team::ValidPlacementExists(t1, t0) != expected_10) {
    throw TestFailureException("");
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"timer", "team0", "team1", "expected_01",
                                       "expected_10"};
  generic_test_main(argc, argv, param_names, "is_array_dominated.tsv",
                    &ValidPlacementExistsWrapper);
  return 0;
}
