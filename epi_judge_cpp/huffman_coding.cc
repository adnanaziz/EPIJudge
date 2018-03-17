#include <string>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_utils_serialization_traits.h"

using std::string;
using std::vector;

namespace huffman {

struct CharWithFrequency {
  char c;
  double freq;
};

double HuffmanEncoding(vector<CharWithFrequency>* symbols) {
  // Implement this placeholder.
  return 0.0;
}

}  // namespace huffman

template <>
struct SerializationTraits<huffman::CharWithFrequency>
    : UserSerTraits<huffman::CharWithFrequency, std::string, double> {
  static huffman::CharWithFrequency FromTuple(
      const std::tuple<std::string, double>& values) {
    if (std::get<0>(values).size() != 1) {
      throw std::runtime_error(
          "CharWithFrequency parser: string length is not 1");
    }
    return huffman::CharWithFrequency{std::get<0>(values)[0],
                                      std::get<1>(values)};
  }
};

double HuffmanEncodingWrapper(vector<huffman::CharWithFrequency> symbols) {
  return huffman::HuffmanEncoding(&symbols);
}

int main(int argc, char* argv[]) {
  // The timeout is set to 15 seconds for each test case.
  // If your program ends with TIMEOUT error, and you want to try longer time
  // limit, you can extend the limit by changing the following line.
  std::chrono::seconds timeout_seconds{15};

  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"symbols"};
  return GenericTestMain(args, timeout_seconds, "huffman_coding.tsv",
                         &HuffmanEncodingWrapper, DefaultComparator{},
                         param_names);
}
