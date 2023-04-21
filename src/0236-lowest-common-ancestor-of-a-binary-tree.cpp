/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes
in the tree.

According to the [definition of LCA on
Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): "The lowest
common ancestor is defined between two nodes `p` and `q` as the lowest node in
`T` that has both `p` and `q` as descendants (where we allow **a node to be a
descendant of itself** )."

 **Example 1:**

![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)



     **Input:** root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1 **Output:** 3
**Explanation:** The LCA of nodes 5 and 1 is 3.

 **Example 2:**

![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)



     **Input:** root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4 **Output:** 5
**Explanation:** The LCA of nodes 5 and 4 is 5, since a node can be a descendant
of itself according to the LCA definition.

 **Example 3:**



     **Input:** root = [1,2], p = 1, q = 2 **Output:** 1

 **Constraints:**

  * The number of nodes in the tree is in the range `[2, 105]`.
  * `-109 <= Node.val <= 109`
  * All `Node.val` are **unique**.
  * `p != q`
  * `p` and `q` will exist in the tree.


*/

#include "leetcode.hpp"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_recursive {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

    TreeNode *ans = nullptr;

    std::function<bool(TreeNode *)> recursive_find = [&](TreeNode *node) {
      if (!node)
        return false;

      // DFS
      bool left = recursive_find(node->left);
      bool right = recursive_find(node->right);

      // if either p or q is the target
      bool mid = node == p or node == q;

      if (left + right + mid >= 2) {
        ans = node;
        return true;
      }

      return left or right or mid;
    };

    recursive_find(root);

    return ans;
  }
};

class Solution_iterative {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    unordered_map<TreeNode *, TreeNode *> parent;
    stack<TreeNode *> st;
    parent[root] = nullptr;
    st.push(root);

    // iterate until p and q are both found
    while (parent.count(p) + parent.count(q) < 2) {
      TreeNode *curr_node = st.top();
      st.pop();

      if (curr_node->left) {
        parent[curr_node->left] = curr_node;
        st.push(curr_node->left);
      }

      if (curr_node->right) {
        parent[curr_node->right] = curr_node;
        st.push(curr_node->right);
      }
    }

    // build ancestor of p
    unordered_set<TreeNode *> ancestors;
    for (; p; p = parent[p])
      ancestors.insert(p);

    // traverse all ancestors of q
    // and see if it's in ancestors of p
    for (; ancestors.count(q) == 0; q = parent[q])
      ;

    return q;
  }
};

TEST_CASE("lowest-common-ancestor-of-a-binary-tree", "[0236]") {
  // Solution sol;
  CHECK(true);
}
