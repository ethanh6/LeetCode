/*
**Example 1:**

![](https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg)



     **Input:** head = [1,2,3,4,5], k = 2 **Output:** [4,5,1,2,3]

 **Example 2:**

![](https://assets.leetcode.com/uploads/2020/11/13/roate2.jpg)



     **Input:** head = [0,1,2], k = 4 **Output:** [2,0,1]

 **Constraints:**

  * The number of nodes in the list is in the range `[0, 500]`.
  * `-100 <= Node.val <= 100`
  * `0 <= k <= 2 * 109`


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
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head)
      return head;

    // close the linked list
    ListNode *ptr = head;
    int n = 1;
    while (ptr->next) {
      ++n;
      ptr = ptr->next;
    }

    ptr->next = head;

    // find new tail
    k %= n;
    ptr = head;
    for (int i = n - k - 1; i; --i)
      ptr = ptr->next;

    // break the ring
    ListNode *newHead = ptr->next;
    ptr->next = nullptr;

    return newHead;
  }
};

TEST_CASE("rotate-list", "[0061]") {
  // Solution sol;
  CHECK(true);
}
