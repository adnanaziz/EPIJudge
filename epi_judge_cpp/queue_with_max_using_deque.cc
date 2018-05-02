
#include <algorithm>
#include <deque>
#include <queue>
#include <stdexcept>
#include <string>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_failure.h"

using std::deque;
using std::length_error;
using std::queue;

template <typename T>
class QueueWithMax {
 public:
  void Enqueue(const T& x) {
    entries_.emplace(x);
    // Eliminate dominated elements in candidates_for_max_.
    while (!empty(candidates_for_max_) && candidates_for_max_.back() < x) {
      candidates_for_max_.pop_back();
    }
    candidates_for_max_.emplace_back(x);
  }

  T Dequeue() {
    if (!empty(entries_)) {
      T result = entries_.front();
      if (result == candidates_for_max_.front()) {
        candidates_for_max_.pop_front();
      }
      entries_.pop();
      return result;
    }
    throw length_error("empty queue");
  }

  const T& Max() const {
    if (!empty(candidates_for_max_)) {
      return candidates_for_max_.front();
    }
    throw length_error("empty queue");
  }

  T& Head() { return entries_.front(); }

  const T& Head() const { return entries_.front(); }

 private:
  queue<T> entries_;
  deque<T> candidates_for_max_;
};

struct QueueOp {
  enum { kConstruct, kDequeue, kEnqueue, kMax } op;
  int argument;

  QueueOp(const std::string& op_string, int arg) : argument(arg) {
    if (op_string == "QueueWithMax") {
      op = kConstruct;
    } else if (op_string == "dequeue") {
      op = kDequeue;
    } else if (op_string == "enqueue") {
      op = kEnqueue;
    } else if (op_string == "max") {
      op = kMax;
    } else {
      throw std::runtime_error("Unsupported queue operation: " + op_string);
    }
  }
};

template <>
struct SerializationTraits<QueueOp> : UserSerTraits<QueueOp, std::string, int> {
};

void QueueTester(const std::vector<QueueOp>& ops) {
  try {
    QueueWithMax<int> q;
    for (auto& x : ops) {
      switch (x.op) {
        case QueueOp::kConstruct:
          break;
        case QueueOp::kDequeue: {
          int result = q.Dequeue();
          if (result != x.argument) {
            throw TestFailure("Dequeue: expected " +
                              std::to_string(x.argument) + ", got " +
                              std::to_string(result));
          }
        } break;
        case QueueOp::kEnqueue:
          q.Enqueue(x.argument);
          break;
        case QueueOp::kMax: {
          int s = q.Max();
          if (s != x.argument) {
            throw TestFailure("Max: expected " + std::to_string(x.argument) +
                              ", got " + std::to_string(s));
          }
        } break;
      }
    }
  } catch (length_error&) {
    throw TestFailure("Unexpected length_error exception");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"ops"};
  return GenericTestMain(args, "queue_with_max_using_deque.cc",
                         "queue_with_max.tsv", &QueueTester,
                         DefaultComparator{}, param_names);
}
