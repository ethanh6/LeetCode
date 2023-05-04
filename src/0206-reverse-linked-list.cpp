/*
Given the `head` of a singly linked list, reverse the list, and return _the
reversed list_.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)



     **Input:** head = [1,2,3,4,5] **Output:** [5,4,3,2,1]

 **Example 2:**

![](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)



     **Input:** head = [1,2] **Output:** [2,1]

 **Example 3:**



     **Input:** head = [] **Output:** []

 **Constraints:**

  * The number of nodes in the list is the range `[0, 5000]`.
  * `-5000 <= Node.val <= 5000`

 **Follow up:** A linked list can be reversed either iteratively or
recursively. Could you implement both?


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
class Solution_recursive {
public:
  ListNode *reverse(ListNode *node, ListNode *prev) {
    if (!node)
      return prev;
    ListNode *next = node->next;
    node->next = prev;
    return reverse(next, node);
  }

  ListNode *reverseList(ListNode *head) { return reverse(head, nullptr); }
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {

    ListNode *prev = nullptr;
    ListNode *ptr = head;

    while (ptr) {
      ListNode *next = ptr->next; // preserve the rest of the list
      ptr->next = prev;
      prev = ptr;
      ptr = next;
    }

    return prev;
  }
};
TEST_CASE("reverse-linked-list", "[0206]") {
  Solution sol;
  CHECK(true);
}
