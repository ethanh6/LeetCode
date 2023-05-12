/*
Given `head`, the head of a linked list, determine if the linked list has a
cycle in it.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)



     **Input:** head = [3,2,0,-4], pos = 1 **Output:** true **Explanation:**
There is a cycle in the linked list, where the tail connects to the 1st node
(0-indexed).

 **Example 2:**

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png)



     **Input:** head = [1,2], pos = 0 **Output:** true **Explanation:** There is
a cycle in the linked list, where the tail connects to the 0th node.

 **Example 3:**

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png)



     **Input:** head = [1], pos = -1 **Output:** false **Explanation:** There is
no cycle in the linked list.

 **Constraints:**

  * The number of the nodes in the list is in the range `[0, 104]`.
  * `-105 <= Node.val <= 105`
  * `pos` is `-1` or a **valid index** in the linked-list.

 **Follow up:** Can you solve it using `O(1)` (i.e. constant) memory?


*/

#include "leetcode.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (!head)
      return false;

    for (ListNode *slow = head, *fast = head->next;
         slow != fast;
         slow = slow->next, fast = fast->next->next)

      // terminal condition
      // when fast reaches end first
      if (!fast or !fast->next)
        return false;

    return true;
  }
};

TEST_CASE("linked-list-cycle", "[0141]") {
  // Solution sol;
  CHECK(true);
}
