/*
Given the `root` of a binary tree, _determine if it is a valid binary search
tree (BST)_.

A **valid BST** is defined as follows:

  * The left subtree of a node contains only nodes with keys **less than** the
node's key.
  * The right subtree of a node contains only nodes with keys **greater than**
the node's key.
  * Both the left and right subtrees must also be binary search trees.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)



     **Input:** root = [2,1,3] **Output:** true

 **Example 2:**

![](https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg)



     **Input:** root = [5,1,4,null,null,3,6] **Output:** false **Explanation:**
The root node's value is 5 but its right child's value is 4.

 **Constraints:**

  * The number of nodes in the tree is in the range `[1, 104]`.
  * `-231 <= Node.val <= 231 - 1`


*/

#include "leetcode.hpp"

// Definition for a binary tree node.
// class TreeNode {
// public:
//   int val;
//   TreeNode *left, *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

class Solution {
public:
  bool validate(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
    // empty tree is valid
    if (!root)
      return true;

    if (minNode && root->val <= minNode->val)
      return false;

    if (maxNode && root->val >= maxNode->val)
      return false;

    return validate(root->left, minNode, root) &&
           validate(root->right, root, maxNode);
  }

  bool isValidBST(TreeNode *root) { return validate(root, nullptr, nullptr); };
};

TEST_CASE("validate-binary-search-tree", "[0098]") {
  // Solution sol;
  CHECK(true);
}
