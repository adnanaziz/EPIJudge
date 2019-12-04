#include <string>

#include "test_framework/fmt_print.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
using std::string;

class ClientsCreditsInfo {
 public:
  void Insert(const string& client_id, int c) {
    // TODO - you fill in here.
    return;
  }
  bool Remove(const string& client_id) {
    // TODO - you fill in here.
    return true;
  }
  int Lookup(const string& client_id) const {
    // TODO - you fill in here.
    return 0;
  }
  void AddAll(int C) {
    // TODO - you fill in here.
    return;
  }
  string Max() const {
    // TODO - you fill in here.
    return "";
  }
};
struct Operation {
  std::string op;
  std::string s_arg;
  int i_arg;
};

std::ostream& operator<<(std::ostream& out, const Operation& op) {
  return out << FmtStr("{}({}, {})", op.op, op.s_arg, op.i_arg);
}

namespace test_framework {
template <>
struct SerializationTrait<Operation>
    : UserSerTrait<Operation, std::string, std::string, int> {};
}  // namespace test_framework
void ClientsCreditsInfoTester(const std::vector<Operation>& ops) {
  ClientsCreditsInfo cr;
  int op_idx = 0;
  for (auto& op : ops) {
    if (op.op == "ClientsCreditsInfo") {
      continue;
    } else if (op.op == "remove") {
      bool result = cr.Remove(op.s_arg);
      if (result != op.i_arg) {
        throw TestFailure()
            .WithProperty(PropertyName::STATE, cr)
            .WithProperty(PropertyName::COMMAND, op)
            .WithMismatchInfo(op_idx, op.i_arg, result);
      }
    } else if (op.op == "max") {
      auto result = cr.Max();
      if (result != op.s_arg) {
        throw TestFailure()
            .WithProperty(PropertyName::STATE, cr)
            .WithProperty(PropertyName::COMMAND, op)
            .WithMismatchInfo(op_idx, op.i_arg, result);
      }
    } else if (op.op == "insert") {
      cr.Insert(op.s_arg, op.i_arg);
    } else if (op.op == "add_all") {
      cr.AddAll(op.i_arg);
    } else if (op.op == "lookup") {
      auto result = cr.Lookup(op.s_arg);
      if (result != op.i_arg) {
        throw TestFailure()
            .WithProperty(PropertyName::STATE, cr)
            .WithProperty(PropertyName::COMMAND, op)
            .WithMismatchInfo(op_idx, op.i_arg, result);
        ;
      }
    }
    op_idx++;
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"ops"};
  return GenericTestMain(args, "adding_credits.cc", "adding_credits.tsv",
                         &ClientsCreditsInfoTester, DefaultComparator{},
                         param_names);
}
