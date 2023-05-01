/*
You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists in a one **sorted** list. The list should be made by
splicing together the nodes of the first two lists.

Return _the head of the merged linked list_.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)



     **Input:** list1 = [1,2,4], list2 = [1,3,4] **Output:** [1,1,2,3,4,4]

 **Example 2:**



     **Input:** list1 = [], list2 = [] **Output:** []

 **Example 3:**



     **Input:** list1 = [], list2 = [0] **Output:** [0]

 **Constraints:**

  * The number of nodes in both lists is in the range `[0, 50]`.
  * `-100 <= Node.val <= 100`
  * Both `list1` and `list2` are sorted in **non-decreasing** order.


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
class Solution_iterative {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode();
    ListNode *cur = dummy;

    while (list1 and list2) {
      if (list1->val < list2->val) {
        cur->next = list1;
        list1 = list1->next;
      } else {
        cur->next = list2;
        list2 = list2->next;
      }
      cur = cur->next;
    }

    while (list1) {
      cur->next = list1;
      list1 = list1->next;
      cur = cur->next;
    }

    while (list2) {
      cur->next = list2;
      list2 = list2->next;
      cur = cur->next;
    }

    return dummy->next;
  }
};

class Solution_recursive {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      if (!list1)
        return list2;
      if (!list2)
        return list1;

      if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
      } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
      }
    }
};

TEST_CASE("merge-two-sorted-lists", "[0021]") {
  // Solution sol;
  CHECK(true);
}
