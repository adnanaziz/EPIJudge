#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"

typedef shared_ptr<ListNode<int>> IntNode;

static inline void Append(IntNode **tailpp, IntNode node) {
  **tailpp = node;
  *tailpp = &node->next;
}

static inline void Merge(IntNode *src1p, IntNode *src2p, IntNode **destTailp, size_t len)
{
  size_t n1 = 0, n2 = 0;
  IntNode src1 = *src1p, src2 = *src2p, *destTail = *destTailp;

  while (n1 < len || n2 < len) {
    if (n1 == len || src1 == nullptr) {
      if (n2 == len || src2 == nullptr) {
        break;
      }
      while (n2++ < len && src2) {
        Append(&destTail, src2);
        src2 = src2->next;
      }
    } else {
      if (n2 == len || src2 == nullptr) {
        while (n1++ < len && src1) {
          Append(&destTail, src1);
          src1 = src1->next;
        }
      } else {
        if (src1->data <= src2->data) {
          ++n1;
          Append(&destTail, src1);
          src1 = src1->next;
        } else {
          ++n2;
          Append(&destTail, src2);
          src2 = src2->next;
        }
      }
    }
  }

  *src1p = src1;
  *src2p = src2;
  *destTail = nullptr; // mark the dest list as terminated
  *destTailp = destTail;
}

IntNode StableSortList(IntNode L) {
  size_t curSrcSize = 1;
  size_t total = 0, n;
  IntNode head = L;
  IntNode src1 = nullptr, src2 = nullptr;
  IntNode *srcTail1 = &src1, *srcTail2 = &src2;

  // split L into src1 and src2
  while (head) {
    Append(&srcTail1, head);
    head = head->next;
    ++total;
    if (head) {
      Append(&srcTail2, head);
      head = head->next;
      ++total;
    }
  }
  *srcTail1 = nullptr;
  *srcTail2 = nullptr;

  while (curSrcSize < total) {
    IntNode dest1 = nullptr, *destTail1 = &dest1;
    IntNode dest2 = nullptr, *destTail2 = &dest2;
    size_t iter = 0;

    // get sorted items of at most curSrcSize items from src1 & src2
    // and put them to dest1 and dest2 alternately
    n = 0;
    while (n < total) {
      Merge(&src1, &src2, &destTail1, curSrcSize);
      n += curSrcSize;
      if (n < total) {
        Merge(&src1, &src2, &destTail2, curSrcSize);
        n += curSrcSize;
      }
      ++iter;
    }
    curSrcSize *= 2;
    src1 = dest1;
    src2 = dest2;
    if (iter == 1) {
      break;
    }
  }

  // now src1 and src2 has one single sorted run, make the final merge
  IntNode dest = nullptr, *destTail = &dest;
  Merge(&src1, &src2, &destTail, total);
  return dest;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "sort_list.cc", "sort_list.tsv", &StableSortList,
                         DefaultComparator{}, param_names);
}
