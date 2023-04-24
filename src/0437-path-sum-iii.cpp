/*
The path does not need to start or end at the root or a leaf, but it must go
downwards (i.e., traveling only from parent nodes to child nodes).

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/04/09/pathsum3-1-tree.jpg)



     **Input:** root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
**Output:** 3 **Explanation:** The paths that sum to 8 are shown.

 **Example 2:**



     **Input:** root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
**Output:** 3

 **Constraints:**

  * The number of nodes in the tree is in the range `[0, 1000]`.
  * `-109 <= Node.val <= 109`
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
  int pathSum(TreeNode *root, int targetSum) {

    unordered_map<long long, int> mp;
    int count = 0;

    std::function<void(TreeNode*, long long)> dfs = [&](TreeNode *node, long long cur_sum) ->void {
      if (!node)
        return;

      // get current prefix sum
      cur_sum += node->val;

      // path contains root
      count += cur_sum == targetSum;

      // add # of times that (cur_sum - targetSum) has occurred already in path
      count += mp[cur_sum - targetSum];

      // add current sum to map, and use it to process children
      mp[cur_sum]++;

      dfs(node->left, cur_sum);
      dfs(node->right, cur_sum);

      // remove current sum from the hashmap
      mp[cur_sum]--;
    };

    dfs(root, 0LL);
    return count;
  }
};

TEST_CASE("path-sum-iii", "[0437]") {
  // Solution sol;
  CHECK(true);
}
