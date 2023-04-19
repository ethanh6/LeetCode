/*
Given the `root` of a binary search tree, and an integer `k`, return _the_
`kth` _smallest value ( **1-indexed** ) of all the values of the nodes in the
tree_.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg)



     **Input:** root = [3,1,4,null,2], k = 1 **Output:** 1

 **Example 2:**

![](https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg)



     **Input:** root = [5,3,6,2,4,null,null,1], k = 3 **Output:** 3

 **Constraints:**

  * The number of nodes in the tree is `n`.
  * `1 <= k <= n <= 104`
  * `0 <= Node.val <= 104`

 **Follow up:** If the BST is modified often (i.e., we can do insert and
delete operations) and you need to find the kth smallest frequently, how would
you optimize?


*/

#include "leetcode.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {

    vector<int> pre_order;

    std::function<void(TreeNode *)> dfs = [&](TreeNode *r) {
      if (!r)
        return;

      dfs(r->left);
      pre_order.push_back(r->val);
      dfs(r->right);
    };

    dfs(root);

    return pre_order[k - 1];
  }
};

TEST_CASE("kth-smallest-element-in-a-bst", "[0230]") {
  // Solution sol;
  CHECK(true);
}
