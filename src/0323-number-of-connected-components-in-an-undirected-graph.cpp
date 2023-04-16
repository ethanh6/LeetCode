#include "leetcode.hpp"

class Solution {
public:
  int countComponents(int n, vector<vector<int>> &edges) {

    vector<vector<int>> adj(n);
    for (const auto &e: edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    vector<bool> visited(n, false);
    std::function<void(const int&)> dfs = [&](const int &node){
      visited[node] = true;
      for (const auto &neighbor: adj[node]) 
        if (!visited[neighbor]) 
          dfs(neighbor);
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (visited[i]) 
        continue;
      dfs(i);
      ans++;
    }

    return ans;
  }
};

TEST_CASE("number-of-connected-components-in-an-undirected-graph", "[0323]") {
  Solution sol;
  int n = 5, output = 2;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
  CHECK(sol.countComponents(n, edges) == output);
}

TEST_CASE("number-of-connected-components-in-an-undirected-graph - 1", "[0323]") {
  Solution sol;
  int n = 5, output = 1;
  vector<vector<int>> edges = { {0, 1}, {1, 2}, {2, 3}, {3, 4}};
  CHECK(sol.countComponents(n, edges) == output);
}
