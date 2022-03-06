#include <string>
#include <unordered_set>

#include "test_framework/generic_test.h"
using std::string;
using std::unordered_set;

int TransformString(unordered_set<string> D, const string& s, const string& t) {
    struct StringAndDistance {
        string word;
        int distance;
    };

    std::queue<StringAndDistance> q;
    q.emplace(StringAndDistance{ s, 0 });
    D.erase(s);

    while (!q.empty()) {
        StringAndDistance sd = q.front();
        if (sd.word == t) {
            return sd.distance;
        }

        string str = sd.word;
        for (int i = 0; i < str.size(); i++) {
            for (int j = 0; j < 26; j++) {
                str[i] = 'a' + j;
                auto iter(D.find(str));
                
                if (iter != D.end()) {
                    q.emplace(StringAndDistance{*iter, sd.distance+1});
                    D.erase(iter);
                }
            }

            str[i] = sd.word[i];
        }
        q.pop();
    }
    return -1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"D", "s", "t"};
  return GenericTestMain(args, "string_transformability.cc",
                         "string_transformability.tsv", &TransformString,
                         DefaultComparator{}, param_names);
}
