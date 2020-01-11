#include <memory>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"

using std::make_unique;
using std::priority_queue;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::unordered_map;
using std::vector;

// namespace is used in order to escape BinaryTreeNode symbol

namespace huffman {

struct BinaryTree;

void AssignHuffmanCode(const shared_ptr<BinaryTree>&, const unique_ptr<string>&,
                       unordered_map<char, string>*);

struct CharWithFrequency {
  char c;
  double freq;
};

struct BinaryTree {
  double aggregate_freq;
  CharWithFrequency* s;
  shared_ptr<BinaryTree> left, right;
};

struct FrequencyComparator {
  bool operator()(const shared_ptr<BinaryTree>& lhs,
                  const shared_ptr<BinaryTree>& rhs) const {
    return lhs->aggregate_freq > rhs->aggregate_freq;
  }
};

double HuffmanEncoding(vector<CharWithFrequency>* symbols) {
  // Initially assigns each symbol into candidates.
  priority_queue<shared_ptr<BinaryTree>, vector<shared_ptr<BinaryTree>>,
                 FrequencyComparator>
      candidates;
  for (CharWithFrequency& s : *symbols) {
    candidates.emplace(new BinaryTree{s.freq, &s, nullptr, nullptr});
  }

  // Keeps combining two nodes until there is one node left.
  while (size(candidates) > 1) {
    shared_ptr<BinaryTree> left = candidates.top();
    candidates.pop();
    shared_ptr<BinaryTree> right = candidates.top();
    candidates.pop();
    candidates.emplace(new BinaryTree{
        left->aggregate_freq + right->aggregate_freq, nullptr, left, right});
  }

  unordered_map<char, string> char_to_encoding;
  // Traverses the binary tree, assigning codes to nodes.
  AssignHuffmanCode(candidates.top(), make_unique<string>(), &char_to_encoding);
  double avg = 0.0;
  for (const CharWithFrequency& s : *symbols) {
    avg += size(char_to_encoding[s.c]) * s.freq / 100.0;
  }
  return avg;
}

void AssignHuffmanCode(const shared_ptr<BinaryTree>& tree,
                       const unique_ptr<string>& code,
                       unordered_map<char, string>* char_to_encoding) {
  if (tree) {
    if (tree->s) {
      // This node is a leaf.
      (*char_to_encoding)[tree->s->c] = *code;
    } else {  // Non-leaf node.
      code->push_back('0');
      AssignHuffmanCode(tree->left, code, char_to_encoding);
      code->back() = '1';
      AssignHuffmanCode(tree->right, code, char_to_encoding);
      code->pop_back();
    }
  }
}

}  // namespace huffman

namespace test_framework {
template <>
struct SerializationTrait<huffman::CharWithFrequency>
    : UserSerTrait<huffman::CharWithFrequency, std::string, double> {
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
}  // namespace test_framework

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
