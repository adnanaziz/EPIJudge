#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

const int kMPG = 20;

// gallons[i] is the amount of gas in city i, and distances[i] is the distance
// city i to the next city.
int FindAmpleCity(const vector<int>& gallons, const vector<int>& distances) {
  int remaining_gallons = 0;
  struct CityAndRemainingGas {
    int city = 0, remaining_gallons = 0;
  };
  CityAndRemainingGas city_remaining_gallons_pair;
  const int num_cities = size(gallons);
  for (int i = 1; i < num_cities; ++i) {
    remaining_gallons += gallons[i - 1] - distances[i - 1] / kMPG;
    if (remaining_gallons < city_remaining_gallons_pair.remaining_gallons) {
      city_remaining_gallons_pair = {i, remaining_gallons};
    }
  }
  return city_remaining_gallons_pair.city;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"gallons", "distances"};
  return GenericTestMain(args, "refueling_schedule.tsv", &FindAmpleCity,
                         DefaultComparator{}, param_names);
}
