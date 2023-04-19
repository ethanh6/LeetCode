#include "leetcode.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {

    TreeNode *successor = nullptr;

    while (root) {

      // if (p->val == root->val) then the successor is on the right sub tree
      // then root will eventually be nullptr.
      //
      // if (p->val > root->val) then the successor is also on the right sub tree
      if (p->val >= root->val) {
        root = root->right;
      }

      // now root is a porential answer
      else {
        successor = root;
        root = root->left;
      }

    }

    return successor;

  }
};

TEST_CASE("inorder-successor-in-bst", "[0285]") {
  // Solution sol;
  CHECK(true);
}
