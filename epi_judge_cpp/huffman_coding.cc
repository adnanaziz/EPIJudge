#include <string>
#include <vector>
#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::string;
using std::vector;
namespace huffman {

struct CharWithFrequency {
  char c;
  double freq;
};
double HuffmanEncoding(vector<CharWithFrequency>* symbols) {
  // TODO - you fill in here.
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
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"symbols"};
  return GenericTestMain(args, "huffman_coding.cc", "huffman_coding.tsv",
                         &HuffmanEncodingWrapper, DefaultComparator{},
                         param_names);
}
