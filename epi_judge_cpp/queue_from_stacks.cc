#include <stdexcept>
#include <string>
#include <vector>

#include "test_framework/test_failure_exception.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::length_error;

class Queue {
 public:
  void Enqueue(int x) {
    // Implement this placeholder.
    return;
  }

  int Dequeue() {
    // Implement this placeholder.
    return 0;
  }
};

struct QueueOp {
  enum { CONSTRUCT, DEQUEUE, ENQUEUE } op;
  int argument;

  QueueOp(const std::string& op_string, int arg) : argument(arg) {
    if (op_string == "Queue") {
      op = CONSTRUCT;
    } else if (op_string == "dequeue") {
      op = DEQUEUE;
    } else if (op_string == "enqueue") {
      op = ENQUEUE;
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
    Queue q;
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
      }
    }
  } catch (length_error&) {
    throw TestFailureException("Unexpected length_error exception");
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> param_names{"ops"};
  generic_test_main(argc, argv, param_names, "queue_from_stacks.tsv",
                    &QueueTester);
  return 0;
}
