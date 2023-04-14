/*
The **height** of a rooted tree is the number of edges on the longest downward
path between the root and a leaf.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2020/09/01/e1.jpg)



     **Input:** n = 4, edges = [[1,0],[1,2],[1,3]] **Output:** [1]
**Explanation:** As shown, the height of the tree is 1 when the root is the node
with label 1 which is the only MHT.

 **Example 2:**

![](https://assets.leetcode.com/uploads/2020/09/01/e2.jpg)



     **Input:** n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]] **Output:** [3,4]

 **Constraints:**

  * `1 <= n <= 2 * 104`
  * `edges.length == n - 1`
  * `0 <= ai, bi < n`
  * `ai != bi`
  * All the pairs `(ai, bi)` are distinct.
  * The given input is **guaranteed** to be a tree and there will be **no
repeated** edges.


*/

#include "leetcode.hpp"

class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    // edge case
    if (n == 1) {
      return {0};
    }

    // build adjacent list graph representation
    map<int, vector<int>> adj;
    for (const auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    // put all leaf nodes into leaves
    vector<int> leaves;
    for (const auto &it : adj) {
      auto [node, neighbors] = it; // structured binding
      if (neighbors.size() == 1)
        leaves.push_back(node);
    }

    // run while only tow nodes left
    while (n > 2) {

      n -= leaves.size();
      vector<int> next_leaves;

      // process all leaves
      for (const auto &i : leaves) {
        // remove a node from the tree
        // j is the parent
        int j = adj[i][0];
        adj.erase(i); // remove leaf from adjacent list

        // remove leaves from neighbor vector of parent
        // this is erase-remove idiom
        adj[j].erase(std::remove(adj[j].begin(), adj[j].end(), i),
                     adj[j].end());

        // if j is now a leaf, push to next_leaves
        if (adj[j].size() == 1) {
          next_leaves.push_back(j);
        }
      }

      // a layer is finished
      leaves = next_leaves;
    }

    return leaves;
  }
};

TEST_CASE("minimum-height-trees", "[0310]") {
  Solution sol;
  int n = 4;
  vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
  vector<int> output{1};
  REQUIRE(sol.findMinHeightTrees(n, edges) == output);
}

TEST_CASE("minimum-height-trees - 1", "[0310]") {
  Solution sol;
  int n = 6;
  vector<vector<int>> edges{{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
  vector<int> output{3, 4};
  REQUIRE(sol.findMinHeightTrees(n, edges) == output);
}

TEST_CASE("minimum-height-trees - 2", "[0310]") {
  Solution sol;
  int n = 1;
  vector<vector<int>> edges{};
  vector<int> output{0};
  REQUIRE(sol.findMinHeightTrees(n, edges) == output);
}

TEST_CASE("minimum-height-trees - 3", "[0310]") {
  Solution sol;
  int n = 6;
  vector<vector<int>> edges{{0, 1}, {0, 2}, {0, 3}, {3, 4}, {4, 5}};
  vector<int> output{3};
  REQUIRE(sol.findMinHeightTrees(n, edges) == output);
}
