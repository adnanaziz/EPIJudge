#include <vector>

#include "test_framework/fmt_print.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::vector;
const int kMPG = 20;

// gallons[i] is the amount of gas in city i, and distances[i] is the distance
// city i to the next city.
int FindAmpleCity(const vector<int>& gallons, const vector<int>& distances) {
    struct City_n_Remainiing_Gallon{
        int city = 0;
        int remaining_gallon = 0;
    };

    City_n_Remainiing_Gallon city_remaining_gln;
    int num_city = gallons.size();

    int remaining_gallon = 0;
    for (int i = 1; i < num_city; i++) {
        remaining_gallon += gallons[i-1] - distances[i-1] / kMPG;
        if (city_remaining_gln.remaining_gallon > remaining_gallon) {
            city_remaining_gln = City_n_Remainiing_Gallon{ i, remaining_gallon };
        }
    }

    return city_remaining_gln.city;
}
void FindAmpleCityWrapper(TimedExecutor& executor, const vector<int>& gallons,
                          const vector<int>& distances) {
  int result = executor.Run([&] { return FindAmpleCity(gallons, distances); });
  const int num_cities = gallons.size();
  int tank = 0;
  for (int i = 0; i < num_cities; ++i) {
    int city = (result + i) % num_cities;
    tank += gallons[city] * kMPG - distances[city];
    if (tank < 0) {
      throw TestFailure(FmtStr("Out of gas on city {}", i));
    }
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "gallons", "distances"};
  return GenericTestMain(args, "refueling_schedule.cc",
                         "refueling_schedule.tsv", &FindAmpleCityWrapper,
                         DefaultComparator{}, param_names);
}
