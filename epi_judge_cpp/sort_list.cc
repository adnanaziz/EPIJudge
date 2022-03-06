#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"

void AddList(shared_ptr<ListNode<int>>* node, shared_ptr<ListNode<int>>* tail) {
    (*tail)->next = (*node);
    (*tail) = (*node);
    (*node) = (*node)->next;
}

shared_ptr<ListNode<int>> MergeTwoSortedList(shared_ptr<ListNode<int>> l1, shared_ptr<ListNode<int>> l2) {

    shared_ptr<ListNode<int>> dummy_head = shared_ptr<ListNode<int>>(new ListNode<int>);
    auto tail = dummy_head;
    while (l1 && l2) {
        AddList(l1->data <= l2->data ? &l1 : &l2, &tail);
    }

    tail->next = l1 ? l1 : l2;
    
    return dummy_head->next;
}

shared_ptr<ListNode<int>> StableSortList(shared_ptr<ListNode<int>> L) {
  
    if (L == nullptr || L->next == nullptr) {
        return L;
    }

    shared_ptr<ListNode<int>> pre_slow = nullptr;
    shared_ptr<ListNode<int>> slow = L;
    shared_ptr<ListNode<int>> fast = L;

    while (fast && fast->next) {
        pre_slow = slow;
        fast = fast->next->next;
        slow = slow->next;
    }

    pre_slow->next = nullptr;

    return MergeTwoSortedList(StableSortList(L), StableSortList(slow));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "sort_list.cc", "sort_list.tsv", &StableSortList,
                         DefaultComparator{}, param_names);
}
