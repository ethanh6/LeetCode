/*
Given the `root` of a binary tree, return _the **maximum width** of the given
tree_.

The **maximum width** of a tree is the maximum **width** among all levels.

The **width** of one level is defined as the length between the end-nodes (the
leftmost and rightmost non-null nodes), where the null nodes between the end-
nodes that would be present in a complete binary tree extending down to that
level are also counted into the length calculation.

It is **guaranteed** that the answer will in the range of a **32-bit** signed
integer.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/05/03/width1-tree.jpg)



     **Input:** root = [1,3,2,5,3,null,9] **Output:** 4 **Explanation:** The
maximum width exists in the third level with length 4 (5,3,null,9).

 **Example 2:**

![](https://assets.leetcode.com/uploads/2022/03/14/maximum-width-of-binary-
tree-v3.jpg)



     **Input:** root = [1,3,2,5,null,null,9,6,null,7] **Output:** 7
**Explanation:** The maximum width exists in the fourth level with length 7
(6,null,null,null,null,null,7).

 **Example 3:**

![](https://assets.leetcode.com/uploads/2021/05/03/width3-tree.jpg)



     **Input:** root = [1,3,2,5] **Output:** 2 **Explanation:** The maximum
width exists in the second level with length 2 (3,2).

 **Constraints:**

  * The number of nodes in the tree is in the range `[1, 3000]`.
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
  int widthOfBinaryTree(TreeNode *root) {
    if (!root)
      return 0;

    queue<pair<TreeNode *, long long>> q;
    long long maxWidth = 0;

    q.push(std::make_pair(root, 0));

    while (!q.empty()) {

      long long start_idx = q.front().second; // idx of left most node in queue
      long long end_idx = q.back().second; // idx of right most node in queue

      // calculate width
      maxWidth = max(maxWidth, end_idx - start_idx + 1);

      // iterate current level using size of queue
      for (int sz = q.size(); sz; --sz, q.pop()) {
        auto node = q.front().first;

        // to avoid overflow, adjust the idx of each node by the first node in level
        long long node_idx = q.front().second - start_idx;

        if (node->left)
          q.push(std::make_pair(node->left, 2LL * node_idx));
        if (node->right)
          q.push(std::make_pair(node->right, 2LL * node_idx + 1));
      }
    }

    return maxWidth;
  }
};

TEST_CASE("maximum-width-of-binary-tree", "[0662]") {
  // Solution sol;
  CHECK(true);
}
