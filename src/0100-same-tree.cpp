/*
Given the roots of two binary trees `p` and `q`, write a function to check if
they are the same or not.

Two binary trees are considered the same if they are structurally identical,
and the nodes have the same value.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2020/12/20/ex1.jpg)

    
    
     **Input:** p = [1,2,3], q = [1,2,3] **Output:** true

 **Example 2:**

![](https://assets.leetcode.com/uploads/2020/12/20/ex2.jpg)

    
    
     **Input:** p = [1,2], q = [1,null,2] **Output:** false

 **Example 3:**

![](https://assets.leetcode.com/uploads/2020/12/20/ex3.jpg)

    
    
     **Input:** p = [1,2,1], q = [1,1,2] **Output:** false

 **Constraints:**

  * The number of nodes in both trees is in the range `[0, 100]`.
  * `-104 <= Node.val <= 104`


*/

#include "leetcode.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if (!p and !q)
        return true;
      if ((!p and q) or (p and !q))
        return false;
      if(p->val != q->val)
        return false;
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

TEST_CASE("same-tree", "[0100]"){
    // Solution sol;
    CHECK(true);
}
