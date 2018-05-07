
#pragma once

#include <memory>
#include <utility>

using std::shared_ptr;


class PostingListNode {
 public:
  int order;
  shared_ptr<PostingListNode> next;
  PostingListNode* jump;
  
  PostingListNode(int order, shared_ptr<PostingListNode> next,
                  PostingListNode* jump)
      : order(order), next(next), jump(jump) {}
  
};

