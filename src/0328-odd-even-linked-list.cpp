/*
Given the `head` of a singly linked list, group all the nodes with odd indices
together followed by the nodes with even indices, and return _the reordered
list_.

The **first** node is considered **odd** , and the **second** node is **even**
, and so on.

Note that the relative order inside both the even and odd groups should remain
as it was in the input.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/10/oddeven-linked-list.jpg)



     **Input:** head = [1,2,3,4,5] **Output:** [1,3,5,2,4]

 **Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/10/oddeven2-linked-list.jpg)



     **Input:** head = [2,1,3,5,6,4,7] **Output:** [2,3,6,7,1,5,4]

 **Constraints:**

  * The number of nodes in the linked list is in the range `[0, 104]`.
  * `-106 <= Node.val <= 106`


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
  ListNode *oddEvenList(ListNode *head) {
    if (!head)
      return head;

    ListNode *odd = head, *even = head->next, *evenHead = even;

    while (odd->next && even->next) {
      odd->next = even->next; // connect odds
      odd = odd->next;
      even->next = odd->next; // connect evens
      even = even->next;
    }

    odd->next = evenHead;

    return head;
  }
};

TEST_CASE("odd-even-linked-list", "[0328]") {
  // Solution sol;
  CHECK(true);
}
