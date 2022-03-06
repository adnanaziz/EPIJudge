#include <algorithm>
#include <vector>
#include <unordered_set>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::vector;

bool CheckOneBitDifference(int x, int y) {
    int bit_diff = x ^ y;
    return bit_diff = bit_diff && !(bit_diff & (bit_diff - 1));
}


bool DirectGrayCode(int num_bits, std::unordered_set<int>* history, vector<int>& results) {

    if (results.size() == (1 << num_bits))
        return CheckOneBitDifference(results.front(), results.back());

    for (int i = 0; i < num_bits; i++) {
        int previous_code = results.back();
        int next_code = previous_code ^ (1 << i);
        if (!history->count(next_code)) {
            history->emplace(next_code);
            results.emplace_back(next_code);
            
            if (DirectGrayCode(num_bits, history, results))
                return true;

            history->erase(next_code);
            results.pop_back();
        }
    }

    return false;
}

vector<int> GrayCodeAnalytic(int num_bits) {
    if (num_bits == 0) {
        return { 0 };
    }

    if (num_bits == 1) {
        return{ 0, 1 };
    }

    auto gray_code_minus_1 = GrayCodeAnalytic(num_bits - 1);
    int next_value = 1 << (num_bits - 1);

    vector<int> reflection;
    for (int indx = gray_code_minus_1.size() -1; indx >= 0; indx--)
        reflection.emplace_back(next_value | gray_code_minus_1[indx]);

    vector<int> results = gray_code_minus_1;
    results.insert(results.end(), reflection.begin(), reflection.end());

    return results;
}

vector<int> GrayCode(int num_bits) {
    return GrayCodeAnalytic(num_bits);
    /*
    vector<int> results({ 0 });
    DirectGrayCode(num_bits, new std::unordered_set<int>({0}), results);
    return results;
    */
}
bool DiffersByOneBit(int x, int y) {
  int bit_difference = x ^ y;
  return bit_difference && !(bit_difference & (bit_difference - 1));
}

void GrayCodeWrapper(TimedExecutor& executor, int num_bits) {
  vector<int> result = executor.Run([&] { return GrayCode(num_bits); });

  int expected_size = (1 << num_bits);
  if (result.size() != expected_size) {
    throw TestFailure("Length mismatch: expected " +
                      std::to_string(expected_size) + ", got " +
                      std::to_string(result.size()));
  }
  for (int i = 1; i < result.size(); i++)
    if (!DiffersByOneBit(result[i - 1], result[i])) {
      if (result[i - 1] == result[i]) {
        throw TestFailure("Two adjacent entries are equal");
      } else {
        throw TestFailure("Two adjacent entries differ by more than 1 bit");
      }
    }

  std::sort(begin(result), end(result));
  auto uniq = std::unique(begin(result), end(result));
  if (uniq != end(result)) {
    throw TestFailure("Not all entries are distinct: found " +
                      std::to_string(std::distance(uniq, end(result))) +
                      " duplicates");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "num_bits"};
  return GenericTestMain(args, "gray_code.cc", "gray_code.tsv",
                         &GrayCodeWrapper, DefaultComparator{}, param_names);
}
