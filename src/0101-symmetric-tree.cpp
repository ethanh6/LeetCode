/*
Given the `root` of a binary tree, _check whether it is a mirror of itself_
(i.e., symmetric around its center).

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg)



     **Input:** root = [1,2,2,3,4,4,3] **Output:** true

 **Example 2:**

![](https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg)



     **Input:** root = [1,2,2,null,3,null,3] **Output:** false

 **Constraints:**

  * The number of nodes in the tree is in the range `[1, 1000]`.
  * `-100 <= Node.val <= 100`

 **Follow up:** Could you solve it both recursively and iteratively?


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
class Solution_rec {
public:
  bool isSymmetric(TreeNode *root) {
    if (!root)
      return true;

    std::function<bool(TreeNode *, TreeNode *)> isSubtreeSymmetric =
        [&](TreeNode *x, TreeNode *y) -> bool {
      if (!x && !y)
        return true;
      if (!x || !y || (x->val != y->val))
        return false;

      return isSubtreeSymmetric(x->left, y->right) &&
             isSubtreeSymmetric(x->right, y->left);
    };

    return isSubtreeSymmetric(root->left, root->right);
  }
};

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    q.push(root);
    while (!q.empty()) {
      auto node1 = q.front();
      q.pop();
      auto node2 = q.front();
      q.pop();

      if (!node1 && !node2)
        continue;
      if (!node1 || !node2 || node1->val != node2->val)
        return false;
      q.push(node1->left);
      q.push(node2->right);
      q.push(node1->right);
      q.push(node2->left);
    }
    return true;
  }
};

TEST_CASE("symmetric-tree", "[0101]") {
  // Solution sol;
  CHECK(true);
}
