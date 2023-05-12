/*
You are given the head of a singly linked-list. The list can be represented
as:



    L0 -> L1 -> … -> Ln - 1 -> Ln

 _Reorder the list to be on the following form:_



    L0 -> Ln -> L1 -> Ln - 1 -> L2 -> Ln - 2 -> …

You may not modify the values in the list's nodes. Only nodes themselves may
be changed.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg)



     **Input:** head = [1,2,3,4] **Output:** [1,4,2,3]

 **Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/09/reorder2-linked-list.jpg)



     **Input:** head = [1,2,3,4,5] **Output:** [1,5,2,4,3]

 **Constraints:**

  * The number of nodes in the list is in the range `[1, 5 * 104]`.
  * `1 <= Node.val <= 1000`


*/

#include "leetcode.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  void reorderList(ListNode *head) {
    stack<ListNode *> st;

    for (ListNode *ptr = head; ptr; ptr = ptr->next)
      st.push(ptr);

    int n = st.size() / 2;

    ListNode *ptr = head;
    while (n--) {
      // pop one node from stack
      ListNode *node = st.top();
      st.pop();

      // reorder the nodes
      node->next = ptr->next;
      ptr->next = node;

      // update ptr
      ptr = ptr->next->next;
    }
    ptr->next = nullptr;
  }
};

TEST_CASE("reorder-list", "[0143]") {
  // Solution sol;
  CHECK(true);
}
