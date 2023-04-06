/*
Given an `m x n` binary matrix `mat`, return _the distance of the nearest_`0`
_for each cell_.

The distance between two adjacent cells is `1`.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/04/24/01-1-grid.jpg)



     **Input:** mat = [[0,0,0],[0,1,0],[0,0,0]] **Output:**
[[0,0,0],[0,1,0],[0,0,0]]

 **Example 2:**

![](https://assets.leetcode.com/uploads/2021/04/24/01-2-grid.jpg)



     **Input:** mat = [[0,0,0],[0,1,0],[1,1,1]] **Output:**
[[0,0,0],[0,1,0],[1,2,1]]

 **Constraints:**

  * `m == mat.length`
  * `n == mat[i].length`
  * `1 <= m, n <= 104`
  * `1 <= m * n <= 104`
  * `mat[i][j]` is either `0` or `1`.
  * There is at least one `0` in `mat`.


*/

#include "leetcode.hpp"

class Solution {
public:
  vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int rows = mat.size(), cols = mat[0].size();

    auto ans = vector<vector<int>>(rows, vector<int>(cols, INT_MAX));
    queue<pair<int, int>> q;

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (mat[i][j] == 0) {
          ans[i][j] = 0;
          q.push(pair<int, int>{i, j});
        }
      }
    }

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      for (const auto &dir : directions) {
        int new_r = cur.first + dir[0], new_c = cur.second + dir[1];
        if (0 <= new_r && new_r < rows && 0 <= new_c && new_c < cols) {
          if (ans[new_r][new_c] > ans[cur.first][cur.second] + 1) {
            ans[new_r][new_c] = ans[cur.first][cur.second] + 1;
            q.push(pair<int, int>{new_r, new_c});
          }
        }
      }
    }

    return ans;
  }
};

TEST_CASE("01-matrix", "[0542]") {
  Solution sol;
  vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  vector<vector<int>> output{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  CHECK(sol.updateMatrix(mat) == output);
}

TEST_CASE("01-matrix - 1", "[0542]") {
  Solution sol;
  vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
  vector<vector<int>> output{{0, 0, 0}, {0, 1, 0}, {1, 2, 1}};
  CHECK(sol.updateMatrix(mat) == output);
}
