#include <string>

#include "test_framework/test_failure_exception.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::string;

class ClientsCreditsInfo {
 public:
  void Insert(const string& client_id, int c) {
    // Implement this placeholder.
    return;
  }

  bool Remove(const string& client_id) {
    // Implement this placeholder.
    return true;
  }

  int Lookup(const string& client_id) const {
    // Implement this placeholder.
    return 0;
  }

  void AddAll(int C) {
    // Implement this placeholder.
    return;
  }

  string Max() const {
    // Implement this placeholder.
    return "";
  }
};

struct Operation {
  std::string op;
  std::string s_arg;
  int i_arg;
};

template <>
struct SerializationTraits<Operation>
    : UserSerTraits<Operation, std::string, std::string, int> {};

void ClientsCreditsInfoTester(const std::vector<Operation>& ops) {
  ClientsCreditsInfo credits;
  for (auto& op : ops) {
    if (op.op == "ClientsCreditsInfo") {
      continue;
    } else if (op.op == "remove") {
      bool result = credits.Remove(op.s_arg);
      if (result != op.i_arg) {
        throw TestFailureException("Remove: return value mismatch");
      }
    } else if (op.op == "max") {
      auto result = credits.Max();
      if (result != op.s_arg) {
        throw TestFailureException("Max: return value mismatch");
      }
    } else if (op.op == "insert") {
      credits.Insert(op.s_arg, op.i_arg);
    } else if (op.op == "add_all") {
      credits.AddAll(op.i_arg);
    } else if (op.op == "lookup") {
      auto result = credits.Lookup(op.s_arg);
      if (result != op.i_arg) {
        throw TestFailureException("Lookup: return value mismatch");
      }
    }
  }
}

#include "test_framework/generic_test.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"ops"};
  GenericTestMain(args, "adding_credits.tsv", &ClientsCreditsInfoTester,
                  DefaultComparator{}, param_names);
  return 0;
}
