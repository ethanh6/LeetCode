/*
Given the `head` of a singly linked list, return `true` _if it is a_
_palindrome_ _or_`false` _otherwise_.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg)



     **Input:** head = [1,2,2,1] **Output:** true

 **Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg)



     **Input:** head = [1,2] **Output:** false

 **Constraints:**

  * The number of nodes in the list is in the range `[1, 105]`.
  * `0 <= Node.val <= 9`

 **Follow up:** Could you do it in `O(n)` time and `O(1)` space?


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
class Solution0 {
public:
  bool isPalindrome(ListNode *head) {
    vector<int> vals;
    ListNode *cur = head;
    while (cur) {
      vals.push_back(cur->val);
      cur = cur->next;
    }

    int lo = 0, hi = vals.size() - 1;

    while (lo < hi)
      if (vals[lo++] != vals[hi--])
        return false;

    return true;
  }
};

// recursion solution
class Solution1 {
public:
  bool isPalindrome(ListNode *head) {
    ListNode *frontPtr = head;

    std::function<bool(ListNode * node)> rec = [&](ListNode *node) -> bool {
      if (node) {
        if (!rec(node->next)) // dfs
          return false;

        if (node->val != frontPtr->val) // check node in reverse order
          return false;
        frontPtr = frontPtr->next;
      }
      return true;
    };
    return rec(head);
  }
};

TEST_CASE("palindrome-linked-list", "[0234]") {
  // Solution sol;
  CHECK(true);
}
