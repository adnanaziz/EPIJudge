#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

// gallons[i] is the amount of gas in city i, and distances[i] is the distance
// city i to the next city.
int FindAmpleCity(const vector<int>& gallons, const vector<int>& distances) {
  // Implement this placeholder.
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"gallons", "distances"};
  return GenericTestMain(args, "refueling_schedule.tsv", &FindAmpleCity,
                         DefaultComparator{}, param_names);
}
