#include <algorithm>
#include <functional>
#include <iterator>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::function;
using std::max;
using std::string;
using std::swap;
using std::unordered_map;
using std::vector;

struct Person {
  int age;
  string name;
};

void GroupByAge(vector<Person>* people) {
  unordered_map<int, int> age_to_count;
  for (const Person& p : *people) {
    ++age_to_count[p.age];
  }
  unordered_map<int, int> age_to_offset;
  int offset = 0;
  for (const auto& [age, count] : age_to_count) {
    age_to_offset[age] = offset;
    offset += count;
  }

  while (!empty(age_to_offset)) {
    auto from = begin(age_to_offset);
    auto to = age_to_offset.find((*people)[from->second].age);
    swap((*people)[from->second], (*people)[to->second]);
    // Use age_to_count to see when we are finished with a particular age.
    --age_to_count[to->first];
    if (age_to_count[to->first] > 0) {
      ++to->second;
    } else {
      age_to_offset.erase(to);
    }
  }
}

namespace test_framework {
template <>
struct SerializationTrait<Person> : UserSerTrait<Person, int, string> {};
}  // namespace test_framework

void GroupByAgeWrapper(TimedExecutor& executor, vector<Person>& people) {
  if (people.empty()) {
    return;
  }
  std::multiset<Person, std::function<bool(Person, Person)>> values(
      begin(people), end(people), [](const Person& a, const Person& b) {
        return a.age == b.age ? a.name < b.name : a.age < b.age;
      });

  executor.Run([&] { GroupByAge(&people); });

  if (people.empty()) {
    throw TestFailure("Empty result");
  }

  std::set<int> ages;
  int last_age = people[0].age;
  for (auto& x : people) {
    if (ages.count(x.age)) {
      throw TestFailure("Entries are not grouped by age");
    }
    if (x.age != last_age) {
      ages.insert(last_age);
      last_age = x.age;
    }
    auto it = values.find(x);
    if (it == end(values)) {
      throw TestFailure("Entry set changed");
    }
    values.erase(it);
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "people"};
  return GenericTestMain(args, "group_equal_entries.cc",
                         "group_equal_entries.tsv", &GroupByAgeWrapper,
                         DefaultComparator{}, param_names);
}
