/*
You are given an `m x n` `grid` where each cell can have one of three values:

  * `0` representing an empty cell,
  * `1` representing a fresh orange, or
  * `2` representing a rotten orange.

Every minute, any fresh orange that is **4-directionally adjacent** to a
rotten orange becomes rotten.

Return _the minimum number of minutes that must elapse until no cell has a
fresh orange_. If _this is impossible, return_ `-1`.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2019/02/16/oranges.png)



     **Input:** grid = [[2,1,1],[1,1,0],[0,1,1]] **Output:** 4

 **Example 2:**



     **Input:** grid = [[2,1,1],[0,1,1],[1,0,1]] **Output:** -1 **Explanation:**
The orange in the bottom left corner (row 2, column 0) is never rotten, because
rotting only happens 4-directionally.

 **Example 3:**



     **Input:** grid = [[0,2]] **Output:** 0 **Explanation:** Since there are
     already no fresh oranges at minute 0, the anser is just 0.

 **Constraints:**

 * `m == grid.length`
 * `n == grid[i].length`
 * `1 <= m, n <= 10`
 * `grid[i][j]` is `0`, `1`, or `2`.


*/

#include "leetcode.hpp"

class Solution {
public:
  int R, C;
  vector<vector<int>> grid;
  vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

  int orangesRotting(vector<vector<int>> &grid) {
    this->R = grid.size();
    this->C = grid[0].size();
    this->grid = grid;

    queue<vector<int>> rotten;
    int fresh = 0;
    int max_step = INT_MIN;

    // build set of rotten oranges
    for (int i = 0; i < this->R; ++i) {
      for (int j = 0; j < this->C; ++j) {
        if (this->grid[i][j] == 2) {
          rotten.push(vector<int>{i, j});
        } else if (this->grid[i][j] == 1) {
          fresh++;
        }
      }
    }

    int minutes = -1;
    rotten.push(vector<int>{-1, -1});
    while (!rotten.empty()) {
      auto node = rotten.front();
      rotten.pop();
      int r = node[0], c = node[1];
      if (r == -1) {
        minutes++;
        if (!rotten.empty()) {
          rotten.push(vector<int>{-1, -1});
        }
      } else {
        for (const auto &d : directions) {
          int new_row = r + d[0], new_col = c + d[1];
          if (0 <= new_row && new_row < this->R && 0 <= new_col &&
              new_col < this->C) {
            if (this->grid[new_row][new_col] == 1) {
              this->grid[new_row][new_col] = 2;
              fresh--;
              rotten.push(vector<int>{new_row, new_col});
            }
          }
        }
      }
    }
    return fresh == 0 ? minutes : -1;
  }
};

TEST_CASE("rotting-oranges", "[0994]") {
  Solution sol;
  CHECK(true);
}
