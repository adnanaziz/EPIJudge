#include <algorithm>
#include <stdexcept>

#define main _main
#include "stack_with_max.cc"
#undef main
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_failure.h"

using std::length_error;
using std::max;

class QueueWithMax {
 public:
  void Enqueue(int x) { enqueue_.Push(x); }

  int Dequeue() {
    if (dequeue_.Empty()) {
      while (!enqueue_.Empty()) {
        dequeue_.Push(enqueue_.Pop());
      }
    }
    if (!dequeue_.Empty()) {
      return dequeue_.Pop();
    }
    throw length_error("Cannot get Dequeue() on empty queue.");
  }

  int Max() const {
    if (!enqueue_.Empty()) {
      return dequeue_.Empty() ? enqueue_.Max()
                              : max(enqueue_.Max(), dequeue_.Max());
    } else if (!dequeue_.Empty()) {
      return dequeue_.Max();
    }
    throw length_error("Cannot get max() on empty queue.");
  }

 private:
  Stack enqueue_, dequeue_;
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
    QueueWithMax q;
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
  } catch (const length_error&) {
    throw TestFailure("Unexpected length_error exception");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"ops"};
  return GenericTestMain(args, "queue_with_max.cc", "queue_with_max.tsv",
                         &QueueTester, DefaultComparator{}, param_names);
}
