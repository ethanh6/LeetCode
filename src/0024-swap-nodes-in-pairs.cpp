/*
**Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg)



     **Input:** head = [1,2,3,4] **Output:** [2,1,4,3]

 **Example 2:**



     **Input:** head = [] **Output:** []

 **Example 3:**



     **Input:** head = [1] **Output:** [1]

 **Constraints:**

  * `0 <= Node.val <= 100`


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
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *prev = dummy;

    while (prev->next && prev->next->next) {
      ListNode *a = prev->next, *b = prev->next->next;
      ListNode *next = b->next;

      prev->next = b;
      b->next = a;
      a->next = next;
      prev = a;
    }

    return dummy->next;
  }
};

TEST_CASE("swap-nodes-in-pairs", "[0024]") {
  // Solution sol;
  CHECK(true);
}
