/*
Given the `root` of a binary tree, the value of a target node `target`, and an
integer `k`, return _an array of the values of all nodes that have a
distance_`k` _from the target node._

You can return the answer in **any order**.

 **Example 1:**

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/28/sketch0.png)



     **Input:** root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
**Output:** [7,4,1]Explanation: The nodes that are a distance 2 from the target
node (with value 5) have values 7, 4, and 1.

 **Example 2:**



     **Input:** root = [1], target = 1, k = 3 **Output:** []

 **Constraints:**

  * The number of nodes in the tree is in the range `[1, 500]`.
  * `0 <= Node.val <= 500`
  * All the values `Node.val` are **unique**.
  * `target` is the value of one of the nodes in the tree.
  * `0 <= k <= 1000`


*/

#include "leetcode.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    // build map to parent
    unordered_map<TreeNode *, TreeNode *> parent;
    function<void(TreeNode *, TreeNode *)> dfs = [&](TreeNode *node, TreeNode *p) -> void {
      if (!node)
        return;
      parent[node] = p;
      dfs(node->left, node);
      dfs(node->right, node);
    };
    dfs(root, nullptr);

    vector<int> ans;
    queue<pair<TreeNode *, int>> q;
    unordered_set<TreeNode *> seen;

    // start from target
    q.push(make_pair(target, 0));

    // BFS
    for (; !q.empty(); q.pop()) {
      auto [node, step] = q.front();

      // terminal condition: found the correct layer
      if (step == k) {
        for (; !q.empty(); q.pop())
          ans.push_back(q.front().first->val);
        break;
      }

      seen.insert(node);

      for (const auto &n :
           vector<TreeNode *>{node->left, node->right, parent[node]})

        // only process valid & not-seen node
        if (n && seen.find(n) == seen.end()) 
          q.push(make_pair(n, step + 1));

    }

    return ans;
  }
};

TEST_CASE("all-nodes-distance-k-in-binary-tree", "0863") {
  // Solution sol;
  CHECK(true);
}
