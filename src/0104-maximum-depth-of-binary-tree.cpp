/*
Given the `root` of a binary tree, return _its maximum depth_.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg)

    
    
     **Input:** root = [3,9,20,null,null,15,7] **Output:** 3

 **Example 2:**

    
    
     **Input:** root = [1,null,2] **Output:** 2

 **Constraints:**

  * The number of nodes in the tree is in the range `[0, 104]`.
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {

      std::function<int(TreeNode*)> depth = [&](TreeNode* node)->int{
        if (!node)
          return 0;

        return max(depth(node->left),  depth(node->right)) + 1;
      };

      return depth(root);
        
    }
};

TEST_CASE("maximum-depth-of-binary-tree", "[0104]"){
    // Solution sol;
    CHECK(true);
}
