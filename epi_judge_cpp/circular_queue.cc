
#include "test_framework/test_failure_exception.h"
#include "test_framework/test_utils_serialization_traits.h"

class Queue {
 public:
  Queue(size_t capacity) {}

  void Enqueue(int x) {
    // Implement this placeholder.
    return;
  }

  int Dequeue() {
    // Implement this placeholder.
    return 0;
  }

  int Size() const {
    // Implement this placeholder.
    return 0;
  }
};

struct QueueOp {
  enum { CONSTRUCT, DEQUEUE, ENQUEUE, SIZE } op;
  int argument;

  QueueOp(const std::string& op_string, int arg) : argument(arg) {
    if (op_string == "Queue") {
      op = CONSTRUCT;
    } else if (op_string == "dequeue") {
      op = DEQUEUE;
    } else if (op_string == "enqueue") {
      op = ENQUEUE;
    } else if (op_string == "size") {
      op = SIZE;
    } else {
      throw std::runtime_error("Unsupported queue operation: " + op_string);
    }
  }

  void execute(Queue& q) const {
    switch (op) {
      case CONSTRUCT:
        // Hack to bypass deleted assign operator
        q.~Queue();
        new (&q) Queue(argument);
        break;
      case DEQUEUE: {
        int result = q.Dequeue();
        if (result != argument) {
          throw TestFailureException("Dequeue: expected " +
                                     std::to_string(argument) + ", got " +
                                     std::to_string(result));
        }
      } break;
      case ENQUEUE:
        q.Enqueue(argument);
        break;
      case SIZE: {
        int s = q.Size();
        if (s != argument) {
          throw TestFailureException("Size: expected " +
                                     std::to_string(argument) + ", got " +
                                     std::to_string(s));
        }
      } break;
    }
  }
};

template <>
struct SerializationTraits<QueueOp> : UserSerTraits<QueueOp, std::string, int> {
};

void QueueTester(const std::vector<QueueOp>& ops) {
  Queue q(0);
  for (auto& op : ops) {
    op.execute(q);
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "circular_queue.tsv", &QueueTester);
  return 0;
}
