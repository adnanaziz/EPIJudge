#include <iterator>
#include <set>
#include <string>
#include <vector>

#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::string;
using std::vector;

struct Person {
  int age;
  string name;
};

void GroupByAge(vector<Person>* people) {
  // Implement this placeholder.
  return;
}

template <>
struct SerializationTraits<Person> : UserSerTraits<Person, int, string> {};

void GroupByAgeWrapper(TestTimer& timer, vector<Person>& people) {
  if (people.empty()) {
    return;
  }
  std::multiset<Person, std::function<bool(Person, Person)>> values(
      begin(people), end(people), [](const Person& a, const Person& b) {
        return a.age == b.age ? a.name < b.name : a.age < b.age;
      });

  timer.Start();
  GroupByAge(&people);
  timer.Stop();

  if (people.empty()) {
    throw TestFailureException("Empty result");
  }
  std::set<int> ages;
  int last_age = people[0].age;
  for (auto& x : people) {
    if (ages.count(x.age) != 0) {
      throw TestFailureException("Entries are not grouped by age");
    }
    if (x.age != last_age) {
      ages.insert(last_age);
      last_age = x.age;
    }
    auto it = values.find(x);
    if (it == end(values)) {
      throw TestFailureException("Entry set changed");
    }
    values.erase(it);
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"timer", "people"};
  generic_test_main(argc, argv, param_names, "group_equal_entries.tsv",
                    &GroupByAgeWrapper);
  return 0;
}
