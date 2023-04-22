/*
Given two integer arrays `preorder` and `inorder` where `preorder` is the
preorder traversal of a binary tree and `inorder` is the inorder traversal of
the same tree, construct and return _the binary tree_.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)



     **Input:** preorder = [3,9,20,15,7], inorder = [9,3,15,20,7] **Output:**
[3,9,20,null,null,15,7]

 **Example 2:**



     **Input:** preorder = [-1], inorder = [-1] **Output:** [-1]

 **Constraints:**

  * `1 <= preorder.length <= 3000`
  * `inorder.length == preorder.length`
  * `-3000 <= preorder[i], inorder[i] <= 3000`
  * `preorder` and `inorder` consist of **unique** values.
  * Each value of `inorder` also appears in `preorder`.
  * `preorder` is **guaranteed** to be the preorder traversal of the tree.
  * `inorder` is **guaranteed** to be the inorder traversal of the tree.


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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int sz = preorder.size();

    // get index in vector inorder
    unordered_map<int, int> inorder_index_map;
    for (int i = 0; i < inorder.size(); ++i)
      inorder_index_map[inorder[i]] = i;

    // idx of the current element in preorder
    int preorder_idx = 0;

    // helper function (recursive)
    std::function<TreeNode *(int, int)> buildTree =
        [&](int left, int right) -> TreeNode * {

      if (left > right)
        return nullptr;

      int root = preorder[preorder_idx++];
      int idx = inorder_index_map[root];

      return new TreeNode(root, buildTree(left, idx - 1), buildTree(idx + 1, right));
    };

    return buildTree(0, sz - 1);
  }
};

TEST_CASE("construct-binary-tree-from-preorder-and-inorder-traversal",
          "[0105]") {
  // Solution sol;
  CHECK(true);
}
