#include <string>
#include <unordered_map>
#include <unordered_set>

#include "test_framework/fmt_print.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
using std::string;

class ClientsCreditsInfo {
 public:
  void Insert(const string& client_id, int c) {
      Remove(client_id);
      client_to_credit_.emplace(client_id, c - offset_);
      credit_to_client_[c - offset_].emplace(client_id);
  }

  bool Remove(const string& client_id) {
      auto iter_client = client_to_credit_.find(client_id);
      if (iter_client != client_to_credit_.end()) {
          credit_to_client_[iter_client->second].erase(client_id);
          if (credit_to_client_[iter_client->second].empty()) {
              credit_to_client_.erase(iter_client->second);
          }

          client_to_credit_.erase(iter_client);
          return true;
      }

      return false;
  }
  int Lookup(const string& client_id) const {
      auto iter = client_to_credit_.find(client_id);
      return (iter == client_to_credit_.end()) ? -1 : iter->second + offset_;
  }

  void AddAll(int C) {
      offset_ += C;
  }
  
  string Max() const {
      auto iter = credit_to_client_.crbegin();
      return (iter == credit_to_client_.crend() || iter->second.empty()) ? "" : *iter->second.cbegin();
 
  }

private:
    int offset_ = 0;
    std::unordered_map<string, int> client_to_credit_;
    std::map<int, std::unordered_set<string>> credit_to_client_;

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
