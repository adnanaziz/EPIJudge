#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

template <typename T>
class QueueWithMax{
public:
    void Enqueue(T item) {
        enteries_.emplace(item);
        while (!collection_with_max_.empty()) {
            if (collection_with_max_.back() >= item) {
                break;
            }
            collection_with_max_.pop_back();
        }

        collection_with_max_.emplace_back(item);
    }

    T Dequeue() {
        if (!enteries_.empty()) {
            T x = enteries_.front();
            
            if (x == collection_with_max_.front()) {
                collection_with_max_.pop_front();
            }

            enteries_.pop();
            return x;
        }
    
        std::length_error("Empty Queue");
    }

    T Max() {
        if (!collection_with_max_.empty()) {
            return collection_with_max_.front();
        }
        
        std::length_error("Empty Queue");
    }

    T Head() {
        if (!enteries_.empty()) {
            return enteries_.front();
        }

        std::length_error("Empty Queue");
    }
private:
    std::queue<T> enteries_;
    std::deque<T> collection_with_max_;
};

struct TrafficElement {
  bool operator==(const TrafficElement& that) const {
    return time == that.time && volume == that.volume;
  }
  
  bool operator > (const TrafficElement& that) const {
      return volume > that.volume || (volume == that.volume && time > that.time);
  }
  
  bool operator >= (const TrafficElement& that) const {
      return *this > that || *this == that;
  }

  int time;
  double volume;
};
vector<TrafficElement> CalculateTrafficVolumes(const vector<TrafficElement>& A,
                                               int w) {
    vector<TrafficElement> result;
    QueueWithMax<TrafficElement> sliding_window;
    for (const auto& trafic_element : A) {
        sliding_window.Enqueue(trafic_element);

        while (trafic_element.time - sliding_window.Head().time > w) {
            sliding_window.Dequeue();
        }

        result.emplace_back(TrafficElement{ trafic_element.time, sliding_window.Max().volume });
    }


    return result;
}

namespace test_framework {
template <>
struct SerializationTrait<TrafficElement>
    : UserSerTrait<TrafficElement, int, double> {};
}  // namespace test_framework

std::ostream& operator<<(std::ostream& out, const TrafficElement& te) {
  return out << '[' << te.time << ", " << te.volume << ']';
};

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "w"};
  return GenericTestMain(args, "max_of_sliding_window.cc",
                         "max_of_sliding_window.tsv", &CalculateTrafficVolumes,
                         DefaultComparator{}, param_names);
}
