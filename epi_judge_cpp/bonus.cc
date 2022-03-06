#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int CalculateBonusInner1(const vector<int>& productivity) {
    struct EmpData {
        int index;
        int productivity;
    };

    std::priority_queue <EmpData, vector<EmpData>, std::function<bool(EmpData, EmpData)>>
        min_heap([](const EmpData& lhs, const EmpData& rhs) -> bool { return lhs.productivity > rhs.productivity; });

    for (int i = 0; i < productivity.size(); i++) {
        min_heap.emplace(EmpData{ i, productivity[i] });
    }

    vector<int> tickets(productivity.size(), 1);

    while (!min_heap.empty()) {
        int next_dev = min_heap.top().index;

        if (next_dev > 0) {
            if (productivity[next_dev] > productivity[next_dev - 1]) {
                tickets[next_dev] = tickets[next_dev - 1] + 1;
            }
        }

        if (next_dev + 1 < productivity.size()) {
            if (productivity[next_dev] > productivity[next_dev + 1]) {
                tickets[next_dev] = std::max(tickets[next_dev], tickets[next_dev + 1] + 1);
            }
        }

        min_heap.pop();
    }

    int result = 0;
    for (auto tkt : tickets) {
        result += tkt;
    }

    return result;
}

int CalculateBonusInner2(const vector<int>& productivity) {
    vector<int> tickets(productivity.size(), 1);

    for (int i = 1; i < productivity.size(); i++) {
        if (productivity[i] > productivity[i - 1]) {
            tickets[i] = tickets[i - 1] + 1;
        }
    }

    for (int i = productivity.size() - 2; i >= 0; i--) {
        if (productivity[i] > productivity[i + 1]) {
            tickets[i] = std::max(tickets[i], tickets[i + 1] + 1);
        }
    }

    int result = 0;
    for (auto tkt : tickets) {
        result += tkt;
    }

    return result;
}
int CalculateBonus(const vector<int>& productivity) {
    //return CalculateBonusInner1(productivity);
    return CalculateBonusInner2(productivity);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"productivity"};
  return GenericTestMain(args, "bonus.cc", "bonus.tsv", &CalculateBonus,
                         DefaultComparator{}, param_names);
}
