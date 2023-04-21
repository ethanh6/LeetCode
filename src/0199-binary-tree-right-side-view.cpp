/*
Given the `root` of a binary tree, imagine yourself standing on the **right
side** of it, return _the values of the nodes you can see ordered from top to
bottom_.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/14/tree.jpg)



     **Input:** root = [1,2,3,null,5,null,4] **Output:** [1,3,4]

 **Example 2:**



     **Input:** root = [1,null,3] **Output:** [1,3]

 **Example 3:**



     **Input:** root = [] **Output:** []

 **Constraints:**

  * The number of nodes in the tree is in the range `[0, 100]`.
  * `-100 <= Node.val <= 100`


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
  vector<int> rightSideView(TreeNode *root) {
    if (!root) 
      return vector<int>{};

    queue<TreeNode *> q;
    q.push(root);
    vector<int> res;
    while (!q.empty()) {
      TreeNode *curr_node = nullptr;
      for (int sz = q.size(); sz; --sz, q.pop()) {
        curr_node = q.front();
        if (curr_node->left) q.push(curr_node->left);
        if (curr_node->right) q.push(curr_node->right);
      }
      res.push_back(curr_node->val);
    }
    return res;
  }
};

TEST_CASE("binary-tree-right-side-view", "[0199]") {
  // Solution sol;
  CHECK(true);
}
