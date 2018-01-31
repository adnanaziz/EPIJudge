#include <tuple>
#include <vector>

#include "test_framework/test_utils_serialization_traits.h"

using std::vector;

struct PairedTasks {
  int task_1, task_2;
};

vector<PairedTasks> OptimumTaskAssignment(vector<int> task_durations) {
  // Implement this placeholder.
  return {};
}

template <>
struct SerializationTraits<PairedTasks> : UserSerTraits<PairedTasks, int, int> {
};

bool operator==(const PairedTasks& lhs, const PairedTasks& rhs) {
  return std::tie(lhs.task_1, lhs.task_2) == std::tie(rhs.task_1, rhs.task_2);
}

std::ostream& operator<<(std::ostream& out, const PairedTasks& t) {
  return EpiPrint(out, std::make_tuple(t.task_1, t.task_2));
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"task_durations"};
  generic_test_main(argc, argv, param_names, "task_pairing.tsv",
                    &OptimumTaskAssignment);
  return 0;
}
