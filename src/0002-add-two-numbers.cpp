/*
You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg)

    
    
     **Input:** l1 = [2,4,3], l2 = [5,6,4] **Output:** [7,0,8] **Explanation:** 342 + 465 = 807.

 **Example 2:**

    
    
     **Input:** l1 = [0], l2 = [0] **Output:** [0]

 **Example 3:**

    
    
     **Input:** l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9] **Output:** [8,9,9,9,0,0,0,1]

 **Constraints:**

  * The number of nodes in each linked list is in the range `[1, 100]`.
  * `0 <= Node.val <= 9`
  * It is guaranteed that the list represents a number that does not have leading zeros.


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *dummy = new ListNode(), *cur = dummy;
      int carry = 0;
      while (l1 or l2 or carry) {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
      }
      return dummy->next;
    }
};

TEST_CASE("add-two-numbers", "[0002]"){
    // Solution sol;
    CHECK(true);
}
