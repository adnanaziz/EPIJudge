#include <algorithm>
#include <iterator>
#include <vector>

#include "test_framework/test_failure_exception.h"

using std::vector;

class Team {
 public:
  explicit Team(const vector<int>& height) {
    transform(begin(height), end(height), back_inserter(players_),
              [](int h) { return Player{h}; });
  }

  // Checks if A can be placed in front of B.
  static bool ValidPlacementExists(const Team& A, const Team& B) {
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

void ValidPlacementExistsWrapper(const vector<int>& h1, const vector<int>& h2,
                                 bool expected12, bool expected21) {
  Team t1(h1), t2(h2);
  bool result12 = Team::ValidPlacementExists(t1, t2);
  if (result12 != expected12) {
    throw TestFailureException("");
  }

  bool result21 = Team::ValidPlacementExists(t2, t1);
  if (result21 != expected21) {
    throw TestFailureException("");
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "is_array_dominated.tsv",
                    &ValidPlacementExistsWrapper);
  return 0;
}
