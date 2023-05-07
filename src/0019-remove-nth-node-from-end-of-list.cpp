/*
Given the `head` of a linked list, remove the `nth` node from the end of the
list and return its head.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg)

    
    
     **Input:** head = [1,2,3,4,5], n = 2 **Output:** [1,2,3,5]

 **Example 2:**

    
    
     **Input:** head = [1], n = 1 **Output:** []

 **Example 3:**

    
    
     **Input:** head = [1,2], n = 1 **Output:** [1]

 **Constraints:**

  * The number of nodes in the list is `sz`.
  * `1 <= sz <= 30`
  * `0 <= Node.val <= 100`
  * `1 <= n <= sz`

 **Follow up:** Could you do this in one pass?


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode *dummy = new ListNode(0, head);
      ListNode *a = dummy, *b = dummy;

      for (int i = 0; i < n + 1; ++i) {
        b = b->next;
      }

      while (b) {
        a = a->next;
        b = b->next;
      }

      a->next = a->next->next;

      return dummy->next;
    }
};

TEST_CASE("remove-nth-node-from-end-of-list", "[0019]"){
    // Solution sol;
    CHECK(true);
}
