/*
Given the `root` of a binary tree, return _the level order traversal of its
nodes ' values_. (i.e., from left to right, level by level).

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)



     **Input:** root = [3,9,20,null,null,15,7] **Output:** [[3],[9,20],[15,7]]

 **Example 2:**



     **Input:** root = [1] **Output:** [[1]]

 **Example 3:**



     **Input:** root = [] **Output:** []

 **Constraints:**

  * The number of nodes in the tree is in the range `[0, 2000]`.
  * `-1000 <= Node.val <= 1000`


*/

#include "leetcode.hpp"

// Definition for a binary tree node.
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    queue<TreeNode *> q;

    if (!root)
      return ans;
    q.push(root);

    while (!q.empty()) {
      ans.push_back(vector<int>{});

      for (int i = 0, sz = q.size(); i < sz; ++i) {
        TreeNode *node = q.front();
        q.pop();

        ans.back().push_back(node->val);

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }

    }
    return ans;
  }
};

TEST_CASE("binary-tree-level-order-traversal", "[0102]") {
  // Solution sol;
  CHECK(true);
}
