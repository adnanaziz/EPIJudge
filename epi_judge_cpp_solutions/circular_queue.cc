#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_failure.h"

using std::length_error;
using std::rotate;
using std::vector;

class Queue {
 public:
  Queue(size_t capacity) {}

  explicit Queue(int capacity) : entries_(capacity) {}

  void Enqueue(int x) {
    if (num_queue_elements == size(entries_)) {  // Needs to resize.
      // Makes the queue elements appear consecutively.
      rotate(begin(entries_), begin(entries_) + head_, end(entries_));
      head_ = 0, tail_ = num_queue_elements;  // Resets head and tail.
      entries_.resize(size(entries_) * kScaleFactor);
    }

    entries_[tail_] = x;
    tail_ = (tail_ + 1) % size(entries_), ++num_queue_elements;
  }

  int Dequeue() {
    if (!num_queue_elements) {
      throw length_error("empty queue");
    }
    --num_queue_elements;
    int result = entries_[head_];
    head_ = (head_ + 1) % size(entries_);
    return result;
  }

  int Size() const { return num_queue_elements; }

 private:
  const int kScaleFactor = 2;
  int head_ = 0, tail_ = 0, num_queue_elements = 0;
  vector<int> entries_;
};

struct QueueOp {
  enum { kConstruct, kDequeue, kEnqueue, kSize } op;
  int argument;

  QueueOp(const std::string& op_string, int arg) : argument(arg) {
    if (op_string == "Queue") {
      op = kConstruct;
    } else if (op_string == "dequeue") {
      op = kDequeue;
    } else if (op_string == "enqueue") {
      op = kEnqueue;
    } else if (op_string == "size") {
      op = kSize;
    } else {
      throw std::runtime_error("Unsupported queue operation: " + op_string);
    }
  }

  void execute(Queue& q) const {
    switch (op) {
      case kConstruct:
        // Hack to bypass deleted assign operator
        q.~Queue();
        new (&q) Queue(argument);
        break;
      case kDequeue: {
        int result = q.Dequeue();
        if (result != argument) {
          throw TestFailure("Dequeue: expected " + std::to_string(argument) +
                            ", got " + std::to_string(result));
        }
      } break;
      case kEnqueue:
        q.Enqueue(argument);
        break;
      case kSize: {
        int s = q.Size();
        if (s != argument) {
          throw TestFailure("Size: expected " + std::to_string(argument) +
                            ", got " + std::to_string(s));
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

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"ops"};
  return GenericTestMain(args, "circular_queue.cc", "circular_queue.tsv",
                         &QueueTester, DefaultComparator{}, param_names);
}
