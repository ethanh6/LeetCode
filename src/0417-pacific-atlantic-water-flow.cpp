/*
There is an `m x n` rectangular island that borders both the **Pacific Ocean**
and **Atlantic Ocean**. The **Pacific Ocean** touches the island's left and
top edges, and the **Atlantic Ocean** touches the island's right and bottom
edges.

The island is partitioned into a grid of square cells. You are given an `m x
n` integer matrix `heights` where `heights[r][c]` represents the **height
above sea level** of the cell at coordinate `(r, c)`.

The island receives a lot of rain, and the rain water can flow to neighboring
cells directly north, south, east, and west if the neighboring cell's height
is **less than or equal to** the current cell's height. Water can flow from
any cell adjacent to an ocean into the ocean.

Return _a **2D list** of grid coordinates _`result` _where_`result[i] = [ri,
ci]` _denotes that rain water can flow from cell_`(ri, ci)` _to **both** the
Pacific and Atlantic oceans_.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/06/08/waterflow-grid.jpg)



     **Input:** heights =
[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]] **Output:**
[[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]] **Explanation:** The following cells
can flow to the Pacific and Atlantic oceans, as shown below:[0,4]: [0,4] ->
Pacific Ocean [1,3]: [1,3] -> [0,3] -> Pacific Ocean [1,4]: [1,4] -> [1,3] ->
[0,3] -> Pacific Ocean [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean [3,0]:
[3,0] -> Pacific Ocean [3,1]: [3,1] -> [3,0] -> Pacific Ocean [4,0]: [4,0] ->
Pacific Ocean        [4,0] -> Atlantic OceanNote that there are other possible
paths for these cells to flow to the Pacific and Atlantic oceans.

 **Example 2:**



     **Input:** heights = [[1]] **Output:** [[0,0]] **Explanation:** The water
can flow from the only cell to the Pacific and Atlantic oceans.

 **Constraints:**

  * `m == heights.length`
  * `n == heights[r].length`
  * `1 <= m, n <= 200`
  * `0 <= heights[r][c] <= 105`


*/

#include "leetcode.hpp"

class Solution {
public:
  int rows, cols;
  vector<int> directions{0, 1, 0, -1, 0};
  bool isValidIdx(int i, int j) {
    return 0 <= i && i < rows && 0 <= j && j < cols;
  }

  void bfs(queue<pair<int, int>> &q, vector<vector<bool>> &visited,
           const vector<vector<int>> &grid) {
    while (!q.empty()) {
      int i = q.front().first, j = q.front().second;
      visited[i][j] = true;
      q.pop();
      for (int k = 0; k < 4; ++k) {
        int ii = i + directions[k], jj = j + directions[k + 1];
        if (isValidIdx(ii, jj) && grid[ii][jj] >= grid[i][j] &&
            !visited[ii][jj]) {
          q.push({ii, jj});
        }
      }
    }
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    rows = heights.size(), cols = heights[0].size();
    vector<vector<int>> ans;

    queue<pair<int, int>> pacific, atlantic;
    vector<vector<bool>> pac_visit(rows, vector<bool>(cols, false)),
        atl_visit(rows, vector<bool>(cols, false));

    // pacific shore
    for (int i = 0; i < cols; ++i)
      pacific.push(pair<int, int>{0, i});
    for (int j = 1; j < rows; ++j)
      pacific.push(pair<int, int>{j, 0});

    // atlantic shore
    for (int i = 0; i < cols; ++i)
      atlantic.push(pair<int, int>{rows - 1, i});
    for (int j = 0; j < rows - 1; ++j)
      atlantic.push(pair<int, int>{j, cols - 1});

    // create a visit grid
    bfs(pacific, pac_visit, heights);
    bfs(atlantic, atl_visit, heights);

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (pac_visit[i][j] && atl_visit[i][j]) {
          ans.push_back(vector<int>{i, j});
        }
      }
    }
    return ans;
  }
};

TEST_CASE("pacific-atlantic-water-flow", "[0417]") {
  Solution sol;
  vector<vector<int>> heights{{1, 2, 2, 3, 5},
                              {3, 2, 3, 4, 4},
                              {2, 4, 5, 3, 1},
                              {6, 7, 1, 4, 5},
                              {5, 1, 1, 2, 4}};
  vector<vector<int>> output{{0, 4}, {1, 3}, {1, 4}, {2, 2},
                             {3, 0}, {3, 1}, {4, 0}};
  CHECK(sol.pacificAtlantic(heights) == output);
}

// TEST_CASE("pacific-atlantic-water-flow - 1", "[0417]") {
//   Solution sol;
//   vector<vector<int>> heights{{1}};
//   vector<vector<int>> output{{0, 0}};
//   CHECK(sol.pacificAtlantic(heights) == output);
// }
