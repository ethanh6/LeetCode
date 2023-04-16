#include "leetcode.hpp"

class Solution {
public:
  bool validTree(int n, vector<vector<int>> &edges) {
    // base case
    if (n - 1 != edges.size()) {
      return false;
    }

    // build adjacent graph representation
    vector<vector<int>> adj(n);
    for (const auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    vector<bool> visited(n, false);

    std::function<void(const int &)> dfs = [&](const int &node) {
      visited[node] = true;
      for (const int &neighbor : adj[node]) {
        if (!visited[neighbor]) {
          dfs(neighbor);
        }
      }
    };

    dfs(0);

    for (const auto &x: visited) 
      if (!x) 
        return false;

    return true;
  }
};

TEST_CASE("graph-valid-tree", "[0261]") {
  Solution sol;
  vector<vector<int>> input{{0, 1}, {0, 2}, {0, 3}, {1, 4}};
  int n = 5;
  CHECK(sol.validTree(n, input));
}

TEST_CASE("graph-valid-tree - 1", "[0261]") {
  Solution sol;
  vector<vector<int>> input{{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
  int n = 5;
  CHECK_FALSE(sol.validTree(n, input));
}

TEST_CASE("graph-valid-tree - 2", "[0261]") {
  Solution sol;
  vector<vector<int>> input{
      {0, 3}, {1, 3}, {2, 3}, {3, 4}, {5, 4},
  };
  int n = 6;
  CHECK(sol.validTree(n, input));
}

TEST_CASE("graph-valid-tree - 3", "[0261]") {
  Solution sol;
  vector<vector<int>> input{{0, 1}, {2, 4}, {2, 3}, {3, 4}};
  int n = 5;
  CHECK_FALSE(sol.validTree(n, input));
}
