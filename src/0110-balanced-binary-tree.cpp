/*
Given a binary tree, determine if it is **height-balanced**.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg)



     **Input:** root = [3,9,20,null,null,15,7] **Output:** true

 **Example 2:**

![](https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg)



     **Input:** root = [1,2,2,3,3,null,null,4,4] **Output:** false

 **Example 3:**



     **Input:** root = [] **Output:** true

 **Constraints:**

  * The number of nodes in the tree is in the range `[0, 5000]`.
  * `-104 <= Node.val <= 104`


*/

#include "leetcode.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution_top_down {
public:
  int getHeight(TreeNode *node) {
    return !node ? 0 : max(getHeight(node->left), getHeight(node->right)) + 1;
  }
  bool isBalanced(TreeNode *root) {
    return !root ? true
                 : abs(getHeight(root->left) - getHeight(root->right)) <= 1 &&
                       isBalanced(root->left) && isBalanced(root->right);
  }
};

class Solution_botton_up {
public:
  int dfsHeight(TreeNode *root) {
    if (root == NULL)
      return 0;

    // if leftHeight or rightHeight is -1, immediately return -1
    int leftHeight = dfsHeight(root->left);
    if (leftHeight == -1)
      return -1;
    int rightHeight = dfsHeight(root->right);
    if (rightHeight == -1)
      return -1;

    return abs(leftHeight - rightHeight) > 1 ? -1
                                             : max(leftHeight, rightHeight) + 1;
  }
  bool isBalanced(TreeNode *root) { return dfsHeight(root) != -1; }
};

TEST_CASE("balanced-binary-tree", "[0110]") {
  // Solution sol;
  CHECK(true);
}
