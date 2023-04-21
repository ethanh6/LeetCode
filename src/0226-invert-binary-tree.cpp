/*
Given the `root` of a binary tree, invert the tree, and return _its root_.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg)



     **Input:** root = [4,2,7,1,3,6,9] **Output:** [4,7,2,9,6,3,1]

 **Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg)



     **Input:** root = [2,1,3] **Output:** [2,3,1]

 **Example 3:**



     **Input:** root = [] **Output:** []

 **Constraints:**

  * The number of nodes in the tree is in the range `[0, 100]`.
  * `-100 <= Node.val <= 100`


*/

#include "leetcode.hpp"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution_recursion {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return nullptr;

    invertTree(root->left);
    invertTree(root->right);
    swap(root->left, root->right);
    return root;
  }
};

class Solution_iterative {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return nullptr;

    queue<TreeNode *> q;
    q.push(root);

    for (; !q.empty(); q.pop()) {
      auto cur = q.front();
      if (!cur)
        continue;
      swap(cur->left, cur->right);
      q.push(cur->left);
      q.push(cur->right);
    }

    return root;
  }
};

TEST_CASE("invert-binary-tree", "[0226]") {
  // Solution sol;
  CHECK(true);
}
