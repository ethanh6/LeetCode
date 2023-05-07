/*
Given the `head` of a linked list, return _the list after sorting it in
**ascending order**_.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2020/09/14/sort_list_1.jpg)



     **Input:** head = [4,2,1,3] **Output:** [1,2,3,4]

 **Example 2:**

![](https://assets.leetcode.com/uploads/2020/09/14/sort_list_2.jpg)



     **Input:** head = [-1,5,3,4,0] **Output:** [-1,0,3,4,5]

 **Example 3:**



     **Input:** head = [] **Output:** []

 **Constraints:**

  * The number of nodes in the list is in the range `[0, 5 * 104]`.
  * `-105 <= Node.val <= 105`

 **Follow up:** Can you sort the linked list in `O(n logn)` time and `O(1)`
memory (i.e. constant space)?


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
  ListNode *sortList(ListNode *head) {
    if (!head or !head->next)
      return head;

    // divide
    ListNode *mid = getMid(head);

    ListNode *left = sortList(head);
    ListNode *right = sortList(mid);

    // conquer
    return merge(left, right);
  }

  ListNode *getMid(ListNode *node) {
    ListNode *midPrev = nullptr;
    while (node and node->next) {
      midPrev = !midPrev ? node : midPrev->next;
      node = node->next->next;
    }
    ListNode *mid = midPrev->next;
    midPrev->next = nullptr;
    return mid;
  }


  // merge two sorted lists
  ListNode *merge(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode();
    ListNode *ptr = dummy;
    while (l1 and l2) {
      if (l1->val < l2->val) {
        ptr->next = l1;
        l1 = l1->next;
      } else {
        ptr->next = l2;
        l2 = l2->next;
      }
      ptr = ptr->next;
    }
    if (l1)
      ptr->next = l1;
    else
      ptr->next = l2;
    return dummy->next;
  }
};

TEST_CASE("sort-list", "[0148]") {
  // Solution sol;
  CHECK(true);
}
