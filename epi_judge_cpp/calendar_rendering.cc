#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

struct Event {
  int start, finish;
};

struct EndPoint {
    
    bool operator < (const EndPoint that) {
    
        return (time != that.time) ? time < that.time : (isStart && !that.isStart);
    }

    int time;
    int isStart;
};

int FindMaxSimultaneousEvents(const vector<Event>& A) {
    vector<EndPoint> vectTime;
    for (const Event& event : A) {
        vectTime.emplace_back(EndPoint{ event.start, true });
        vectTime.emplace_back(EndPoint{ event.finish, false });
    }

    std::sort(vectTime.begin(), vectTime.end());

    int max_cuncurrent_count = 0, present_count = 0;

    for(const EndPoint& ep : vectTime){
        if (ep.isStart) {
            present_count++;
            max_cuncurrent_count = std::max(max_cuncurrent_count, present_count);
        }
        else {
            present_count--;
        }

    }
    return max_cuncurrent_count;
}

namespace test_framework {
template <>
struct SerializationTrait<Event> : UserSerTrait<Event, int, int> {};
}  // namespace test_framework

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "calendar_rendering.cc",
                         "calendar_rendering.tsv", &FindMaxSimultaneousEvents,
                         DefaultComparator{}, param_names);
}
