/*
Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land)
and `'0'`s (water), return _the number of islands_.

An **island** is surrounded by water and is formed by connecting adjacent
lands horizontally or vertically. You may assume all four edges of the grid
are all surrounded by water.

 **Example 1:**



     **Input:** grid = [  ["1","1","1","1","0"],  ["1","1","0","1","0"],  ["1","1","0","0","0"],  ["0","0","0","0","0"]] **Output:** 1

 **Example 2:**



     **Input:** grid = [  ["1","1","0","0","0"],  ["1","1","0","0","0"],  ["0","0","1","0","0"],  ["0","0","0","1","1"]] **Output:** 3

 **Constraints:**

  * `m == grid.length`
  * `n == grid[i].length`
  * `1 <= m, n <= 300`
  * `grid[i][j]` is `'0'` or `'1'`.


*/

#include "leetcode.hpp"

class Solution {
public:
    int R, C;
    vector<vector<char>> grid;

    void dfs(int i, int j)
    {
        if (!(0 <= i && i < R && 0 <= j && j < C) || this->grid[i][j] != '1')
        {
            return;
        }
        this->grid[i][j] = '0';
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        this->grid = grid;
        this->R = grid.size();
        this->C = grid[0].size();

        int answer = 0;

        for (int i = 0; i < this->R; ++i)
        {
            for (int j = 0; j < this->C; ++j)
            {
                if (this->grid[i][j] == '1')
                {
                    dfs(i, j);
                    answer++;
                }
            }
        }

        return answer;
    }
};

TEST_CASE("number-of-islands", "[0200]")
{
    Solution sol;
    CHECK(true);
}