#include <vector>

#include "test_framework/test_failure_exception.h"
#include "test_framework/test_utils_serialization_traits.h"

class LruCache {
 public:
  LruCache(size_t capacity) {}

  int Lookup(int isbn) {
    // Implement this placeholder.
    return 0;
  }

  void Insert(int isbn, int price) {
    // Implement this placeholder.
    return;
  }

  bool Erase(int isbn) {
    // Implement this placeholder.
    return true;
  }
};

struct Op {
  std::string code;
  int arg1;
  int arg2;
};

template <>
struct SerializationTraits<Op> : UserSerTraits<Op, std::string, int, int> {};

void RunTest(const std::vector<Op>& commands) {
  if (commands.empty() || commands[0].code != "LruCache") {
    throw std::runtime_error("Expected LruCache as first command");
  }
  LruCache cache(commands[0].arg1);

  for (int i = 1; i < commands.size(); i++) {
    auto& cmd = commands[i];
    if (cmd.code == "lookup") {
      int result = cache.Lookup(cmd.arg1);
      if (result != cmd.arg2) {
        throw TestFailureException("Lookup: expected " +
                                   std::to_string(cmd.arg2) + ", got " +
                                   std::to_string(result));
      }
    } else if (cmd.code == "insert") {
      cache.Insert(cmd.arg1, cmd.arg2);
    } else if (cmd.code == "erase") {
      bool result = cache.Erase(cmd.arg1);
      if (result != cmd.arg2) {
        throw TestFailureException("Erase: expected " +
                                   std::to_string(cmd.arg2) + ", got " +
                                   std::to_string(result));
      }
    } else {
      throw std::runtime_error("Unexpected command " + cmd.code);
    }
  }
}

#include "test_framework/test_utils_generic_main.h"

int main(int argc, char* argv[]) {
  generic_test_main(argc, argv, "lru_cache.tsv", &RunTest);
  return 0;
}
