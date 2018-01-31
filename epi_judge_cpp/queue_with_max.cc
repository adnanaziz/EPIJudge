#include <stdexcept>

#include "test_framework/test_failure_exception.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::length_error;

class QueueWithMax {
 public:
  void Enqueue(int x) {
    // Implement this placeholder.
    return;
  }

  int Dequeue() {
    // Implement this placeholder.
    return 0;
  }

  int Max() const {
    // Implement this placeholder.
    return 0;
  }
};

struct QueueOp {
  enum { CONSTRUCT, DEQUEUE, ENQUEUE, MAX } op;
  int argument;

  QueueOp(const std::string& op_string, int arg) : argument(arg) {
    if (op_string == "QueueWithMax") {
      op = CONSTRUCT;
    } else if (op_string == "dequeue") {
      op = DEQUEUE;
    } else if (op_string == "enqueue") {
      op = ENQUEUE;
    } else if (op_string == "max") {
      op = MAX;
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
        case QueueOp::CONSTRUCT:
          break;
        case QueueOp::DEQUEUE: {
          int result = q.Dequeue();
          if (result != x.argument) {
            throw TestFailureException("Dequeue: expected " +
                                       std::to_string(x.argument) + ", got " +
                                       std::to_string(result));
          }
        } break;
        case QueueOp::ENQUEUE:
          q.Enqueue(x.argument);
          break;
        case QueueOp::MAX: {
          int s = q.Max();
          if (s != x.argument) {
            throw TestFailureException("Max: expected " +
                                       std::to_string(x.argument) + ", got " +
                                       std::to_string(s));
          }
        } break;
      }
    }
  } catch (const length_error&) {
    throw TestFailureException("Unexpected length_error exception");
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"ops"};
  generic_test_main(argc, argv, param_names, "queue_with_max.tsv",
                    &QueueTester);
  return 0;
}
