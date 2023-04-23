/*
Given the `root` of a binary tree, return _the zigzag level order traversal of
its nodes ' values_. (i.e., from left to right, then right to left for the
next level and alternate between).

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)



     **Input:** root = [3,9,20,null,null,15,7] **Output:** [[3],[20,9],[15,7]]

 **Example 2:**



     **Input:** root = [1] **Output:** [[1]]

 **Example 3:**



     **Input:** root = [] **Output:** []

 **Constraints:**

  * The number of nodes in the tree is in the range `[0, 2000]`.
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
class Solution_BFS {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;

    if (!root)
      return res;

    bool reverse = false;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      vector<int> level{};
      for (int sz = q.size(); sz; --sz, q.pop()) {
        TreeNode *node = q.front();
        level.push_back(node->val);

        if (node->left)
          q.push(node->left);

        if (node->right)
          q.push(node->right);
      }

      if (reverse)
        std::reverse(level.begin(), level.end());

      reverse = !reverse;
      res.push_back(level);
    }

    return res;
  }
};

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;

    if (!root)
      return res;

    std::function<void(TreeNode *, int)> dfs = [&](TreeNode *node,
                                                   int level) -> void {

      // when new level in res needed to be created
      if (level >= res.size())
        res.push_back(vector<int>{});

      // when in odd level, push in front
      if (level & 1) {
        res[level].emplace(res[level].begin(), node->val);
      } else {
        res[level].emplace(res[level].end(), node->val);
      }

      if (node->left)
        dfs(node->left, level + 1);
      if (node->right)
        dfs(node->right, level + 1);
    };

    dfs(root, 0);

    return res;
  }
};

TEST_CASE("binary-tree-zigzag-level-order-traversal", "[0103]") {
  // Solution sol;
  CHECK(true);
}
