#include <array>
#include <vector>

#include "test_framework/test_failure_exception.h"
#include "test_framework/test_timer.h"

using std::vector;

typedef enum { RED, WHITE, BLUE } Color;

void DutchFlagPartition(int pivot_index, vector<Color>* A_ptr) {
  // Implement this placeholder.
  return;
}

void DutchFlagPartitionWrapper(TestTimer& timer, const vector<int>& data,
                               int pivot_idx) {
  vector<Color> colors;
  colors.resize(data.size());
  std::array<int, 3> count = {0, 0, 0};
  for (size_t i = 0; i < data.size(); i++) {
    count[data[i]]++;
    colors[i] = static_cast<Color>(data[i]);
  }
  Color pivot = colors[pivot_idx];

  timer.Start();
  DutchFlagPartition(pivot_idx, &colors);
  timer.Stop();

  int i = 0;
  while (i < colors.size() && colors[i] < pivot) {
    count[colors[i]]--;
    ++i;
  }

  while (i < colors.size() && colors[i] == pivot) {
    count[colors[i]]--;
    ++i;
  }

  while (i < colors.size() && colors[i] > pivot) {
    count[colors[i]]--;
    ++i;
  }

  if (i != colors.size() || count != std::array<int, 3>{0, 0, 0}) {
    throw TestFailureException("Invalid output");
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "dutch_national_flag.tsv",
                    &DutchFlagPartitionWrapper);
  return 0;
}
