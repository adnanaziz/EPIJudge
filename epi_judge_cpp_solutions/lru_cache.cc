#include <iterator>
#include <list>
#include <unordered_map>
#include <utility>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
#include "test_framework/test_failure.h"

using std::list;
using std::pair;
using std::unordered_map;

class LruCache {
 public:
  LruCache(size_t capacity) {}

  explicit LruCache(int capacity) : capacity_(capacity) {}

  int Lookup(int isbn) {
    if (auto it = isbn_price_table_.find(isbn); it == end(isbn_price_table_)) {
      return -1;
    } else {
      int price = it->second.second;
      // Since key has just been accessed, move it to the front.
      MoveToFront(isbn, it);
      return price;
    }
  }

  void Insert(int isbn, int price) {
    // We add the value for key only if key is not present - we don't update
    // existing values.
    if (auto it = isbn_price_table_.find(isbn); it != end(isbn_price_table_)) {
      // Specification says we should make isbn the most recently used.
      MoveToFront(isbn, it);
    } else {
      if (size(isbn_price_table_) == capacity_) {
        // Removes the least recently used ISBN to get space.
        isbn_price_table_.erase(lru_queue_.back());
        lru_queue_.pop_back();
      }
      lru_queue_.emplace_front(isbn);
      isbn_price_table_[isbn] = {begin(lru_queue_), price};
    }
  }

  bool Erase(int isbn) {
    if (auto it = isbn_price_table_.find(isbn); it == end(isbn_price_table_)) {
      return false;
    } else {
      lru_queue_.erase(it->second.first);
      isbn_price_table_.erase(it);
      return true;
    }
  }

 private:
  using Table = unordered_map<int, pair<list<int>::iterator, int>>;

  // Forces this key-value pair to move to the front.
  void MoveToFront(int isbn, const Table::iterator& it) {
    lru_queue_.erase(it->second.first);
    lru_queue_.emplace_front(isbn);
    it->second.first = begin(lru_queue_);
  }

  int capacity_;
  Table isbn_price_table_;
  list<int> lru_queue_;
};

struct Op {
  std::string code;
  int arg1;
  int arg2;
};

namespace test_framework {
template <>
struct SerializationTrait<Op> : UserSerTrait<Op, std::string, int, int> {};
}  // namespace test_framework

void LruCacheTester(const std::vector<Op>& commands) {
  if (commands.empty() || commands[0].code != "LruCache") {
    throw std::runtime_error("Expected LruCache as first command");
  }
  LruCache cache(commands[0].arg1);

  for (int i = 1; i < commands.size(); i++) {
    auto& cmd = commands[i];
    if (cmd.code == "lookup") {
      int result = cache.Lookup(cmd.arg1);
      if (result != cmd.arg2) {
        throw TestFailure("Lookup: expected " + std::to_string(cmd.arg2) +
                          ", got " + std::to_string(result));
      }
    } else if (cmd.code == "insert") {
      cache.Insert(cmd.arg1, cmd.arg2);
    } else if (cmd.code == "erase") {
      bool result = cache.Erase(cmd.arg1);
      if (result != cmd.arg2) {
        throw TestFailure("Erase: expected " + std::to_string(cmd.arg2) +
                          ", got " + std::to_string(result));
      }
    } else {
      throw std::runtime_error("Unexpected command " + cmd.code);
    }
  }
}

// clang-format off


int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"commands"};
  return GenericTestMain(args, "lru_cache.cc", "lru_cache.tsv", &LruCacheTester,
                         DefaultComparator{}, param_names);
}
// clang-format on
