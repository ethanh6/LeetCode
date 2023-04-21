/*
Given the `root` of a binary tree, return _the length of the **diameter** of
the tree_.

The **diameter** of a binary tree is the **length** of the longest path
between any two nodes in a tree. This path may or may not pass through the
`root`.

The **length** of a path between two nodes is represented by the number of
edges between them.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/06/diamtree.jpg)



     **Input:** root = [1,2,3,4,5] **Output:** 3 **Explanation:** 3 is the
length of the path [4,2,1,3] or [5,2,1,3].

 **Example 2:**



     **Input:** root = [1,2] **Output:** 1

 **Constraints:**

  * The number of nodes in the tree is in the range `[1, 104]`.
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
  int diameterOfBinaryTree(TreeNode *root) {

    int diameter = 0;

    std::function<int(TreeNode *)> longest_path = [&](TreeNode *node) -> int {
      if (!node)
        return 0;

      int left_path = longest_path(node->left);
      int right_path = longest_path(node->right);

      // update diameter on-the-fly
      diameter = max(diameter, left_path + right_path);

      return max(left_path, right_path) + 1;
    };

    longest_path(root);

    return diameter;

  }
};

TEST_CASE("diameter-of-binary-tree", "[0543]") {
  // Solution sol;
  CHECK(true);
}
