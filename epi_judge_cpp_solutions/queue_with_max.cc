#include <algorithm>
#include <stdexcept>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_failure.h"

#define main _main
#define ProgramConfig _ProgramConfig
#include "stack_with_max.cc"
#undef main
#undef ProgramConfig

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
    return dequeue_.Pop();
  }

  int Max() const {
    if (!enqueue_.Empty()) {
      return dequeue_.Empty() ? enqueue_.Max()
                              : max(enqueue_.Max(), dequeue_.Max());
    }
    return dequeue_.Max();
  }

 private:
  Stack enqueue_, dequeue_;
};

struct QueueOp {
  enum class Operation { kConstruct, kDequeue, kEnqueue, kMax } op;
  int argument;

  QueueOp(const std::string& op_string, int arg) : argument(arg) {
    if (op_string == "QueueWithMax") {
      op = Operation::kConstruct;
    } else if (op_string == "dequeue") {
      op = Operation::kDequeue;
    } else if (op_string == "enqueue") {
      op = Operation::kEnqueue;
    } else if (op_string == "max") {
      op = Operation::kMax;
    } else {
      throw std::runtime_error("Unsupported queue operation: " + op_string);
    }
  }
};

namespace test_framework {
template <>
struct SerializationTrait<QueueOp> : UserSerTrait<QueueOp, std::string, int> {};
}  // namespace test_framework

void QueueTester(const std::vector<QueueOp>& ops) {
  try {
    QueueWithMax q;
    for (auto& x : ops) {
      switch (x.op) {
        case QueueOp::Operation::kConstruct:
          break;
        case QueueOp::Operation::kDequeue: {
          int result = q.Dequeue();
          if (result != x.argument) {
            throw TestFailure("Dequeue: expected " +
                              std::to_string(x.argument) + ", got " +
                              std::to_string(result));
          }
        } break;
        case QueueOp::Operation::kEnqueue:
          q.Enqueue(x.argument);
          break;
        case QueueOp::Operation::kMax: {
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

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"ops"};
  return GenericTestMain(args, "queue_with_max.cc", "queue_with_max.tsv", &QueueTester,
                         DefaultComparator{}, param_names);
}
// clang-format on
