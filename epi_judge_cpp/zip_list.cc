#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"
using std::shared_ptr;

void ReverseList(shared_ptr<ListNode<int>>& list_head) {
    if(list_head){
        auto list_iter = list_head;
        shared_ptr<ListNode<int>> prev = nullptr;
        
        while (list_iter) {
            auto temp = list_iter->next;
            list_iter->next = prev;
            prev = list_iter;
            list_iter = temp;
        }
    
        list_head = prev;
    }
}

shared_ptr<ListNode<int>> ZippingLinkedList(
    const shared_ptr<ListNode<int>>& L) {
    if (!L || !L->next)
        return L;

    auto fast = L, slow = L;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    auto first_half_head = L, second_half_head = slow->next;
    slow->next = nullptr;

    ReverseList(second_half_head);

    auto first_iter = first_half_head, second_iter = second_half_head;
    while (second_iter) {
        auto temp = second_iter->next;
        second_iter->next = first_iter->next;
        first_iter->next = second_iter;
        first_iter = first_iter->next->next;
        second_iter = temp;
    }
    return first_half_head;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "zip_list.cc", "zip_list.tsv",
                         &ZippingLinkedList, DefaultComparator{}, param_names);
}
