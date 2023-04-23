/*
Given the `root` of a binary tree and an integer `targetSum`, return _all
**root-to-leaf** paths where the sum of the node values in the path equals
_`targetSum` _. Each path should be returned as a list of the node **values**
, not node references_.

A **root-to-leaf** path is a path starting from the root and ending at any
leaf node. A **leaf** is a node with no children.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg)



     **Input:** root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
**Output:** [[5,4,11,2],[5,8,4,5]] **Explanation:** There are two paths whose
sum equals targetSum:5 + 4 + 11 + 2 = 225 + 8 + 4 + 5 = 22

 **Example 2:**

![](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)



     **Input:** root = [1,2,3], targetSum = 5 **Output:** []

 **Example 3:**



     **Input:** root = [1,2], targetSum = 0 **Output:** []

 **Constraints:**

  * The number of nodes in the tree is in the range `[0, 5000]`.
  * `-1000 <= Node.val <= 1000`
  * `-1000 <= targetSum <= 1000`


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
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> ans;

    std::function<void(TreeNode *, vector<int>, int)> dfs =
        [&](TreeNode *node, vector<int> path, int sum) -> void {
      path.push_back(node->val);
      sum += node->val;

      // this is leaf!
      if (!node->left && !node->right) {
        if (sum == targetSum)
          ans.push_back(path);
        return;
      }

      if (node->left)
        dfs(node->left, path, sum);

      if (node->right)
        dfs(node->right, path, sum);
    };

    if (root)
      dfs(root, vector<int>{}, 0);

    return ans;
  }
};

TEST_CASE("path-sum-ii", "[0113]") {
  // Solution sol;
  CHECK(true);
}
