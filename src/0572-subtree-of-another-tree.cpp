/*
Given the roots of two binary trees `root` and `subRoot`, return `true` if
there is a subtree of `root` with the same structure and node values of`
subRoot` and `false` otherwise.

A subtree of a binary tree `tree` is a tree that consists of a node in `tree`
and all of this node's descendants. The tree `tree` could also be considered
as a subtree of itself.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/04/28/subtree1-tree.jpg)



     **Input:** root = [3,4,5,1,2], subRoot = [4,1,2] **Output:** true

 **Example 2:**

![](https://assets.leetcode.com/uploads/2021/04/28/subtree2-tree.jpg)



     **Input:** root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
**Output:** false

 **Constraints:**

  * The number of nodes in the `root` tree is in the range `[1, 2000]`.
  * The number of nodes in the `subRoot` tree is in the range `[1, 1000]`.
  * `-104 <= root.val <= 104`
  * `-104 <= subRoot.val <= 104`


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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {

    function<bool(TreeNode *, TreeNode *)> isSameTree =
        [&](TreeNode *x, TreeNode *y) -> bool {
      if (!x && !y)
        return true;
      if (!x || !y || x->val != y->val)
        return false;
      return isSameTree(x->left, y->left) && isSameTree(x->right, y->right);
    };

    function<bool(TreeNode *)> dfs = [&](TreeNode *n) -> bool {
      if (!n)
        return false;
      // if roots match
      if (n->val == subRoot->val && isSameTree(n, subRoot)) {
        return true;
      } else {
        return dfs(n->left) || dfs(n->right);
      }
    };

    return dfs(root);
  }
};

TEST_CASE("subtree-of-another-tree", "[0572]") {
  // Solution sol;
  CHECK(true);
}
