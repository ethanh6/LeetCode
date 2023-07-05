/*
There is a robot on an `m x n` grid. The robot is initially located at the
**top-left corner** (i.e., `grid[0][0]`). The robot tries to move to the
**bottom-right corner** (i.e., `grid[m - 1][n - 1]`). The robot can only move
either down or right at any point in time.

Given the two integers `m` and `n`, return _the number of possible unique
paths that the robot can take to reach the bottom-right corner_.

The test cases are generated so that the answer will be less than or equal to
`2 * 109`.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)



     **Input:** m = 3, n = 7 **Output:** 28

 **Example 2:**



     **Input:** m = 3, n = 2 **Output:** 3 **Explanation:** From the top-left
corner, there are a total of 3 ways to reach the bottom-right corner:1. Right ->
Down -> Down2. Down -> Down -> Right3. Down -> Right -> Down

 **Constraints:**

  * `1 <= m, n <= 100`


*/

#include "leetcode.hpp"

class Solution {
public:
  int uniquePaths(int m, int n) {

    // dp[i][j] is the solution for a (i x j) grid
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // base cases
    dp[0][0] = 1;
    for (int i = 1; i < m; ++i)
      dp[i][0] = 1;
    for (int j = 1; j < n; ++j)
      dp[0][j] = 1;

    // fill the table
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp.back().back();
  }
};

TEST_CASE("unique-paths", "[0062]") {
  Solution sol;
  int m = 3, n = 7, output = 28;
  CHECK(sol.uniquePaths(m, n) == output);
}

TEST_CASE("unique-paths - 1", "[0062]") {
  Solution sol;
  int m = 3, n = 2, output = 3;
  CHECK(sol.uniquePaths(m, n) == output);
}
