/*
G3badiven an `m x n` integer matrix `matrix`, if an element is `0`, set its entire
row and column to `0`'s.

You must do it [in place](https://en.wikipedia.org/wiki/In-place_algorithm).

 **Example 1:**

![](https://assets.leetcode.com/uploads/2020/08/17/mat1.jpg)



     **Input:** matrix = [[1,1,1],[1,0,1],[1,1,1]] **Output:**
[[1,0,1],[0,0,0],[1,0,1]]

 **Example 2:**

![](https://assets.leetcode.com/uploads/2020/08/17/mat2.jpg)



     **Input:** matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]] **Output:**
[[0,0,0,0],[0,4,5,0],[0,3,1,0]]

 **Constraints:**

  * `m == matrix.length`
  * `n == matrix[0].length`
  * `1 <= m, n <= 200`
  * `-231 <= matrix[i][j] <= 231 - 1`

 **Follow up:**

  * A straightforward solution using `O(mn)` space is probably a bad idea.
  * A simple improvement uses `O(m + n)` space, but still not the best solution.
  * Could you devise a constant space solution?

  i

*/

#include "leetcode.hpp"

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();

    // edge case: first col and row need to be set to zero.
    bool setFirstRow = false, setFirstCol = false;

    // set flags
    for (int j = 0; j < m; ++j)
      if (matrix[0][j] == 0)
        setFirstRow = true;

    for (int i = 0; i < n; ++i)
      if (matrix[i][0] == 0)
        setFirstCol = true;

    for (int i = 1; i < n; ++i)
      for (int j = 1; j < m; ++j)
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }

    // update matrix except the ones for flags
    for (int i = 1; i < n; ++i)
      for (int j = 1; j < m; ++j)
        if (matrix[i][0] == 0 || matrix[0][j] == 0)
          matrix[i][j] = 0;

    if (matrix[0][0] == 0) {
      for (int i = 0; i < m; ++i)
        matrix[0][i] = 0;

      for (int j = 0; j < n; ++j)
        matrix[j][0] = 0;

    } else {
      if (setFirstRow) 
        for (int i = 0; i < m; ++i)
          matrix[0][i] = 0;

      if (setFirstCol) 
        for (int i = 0; i < n; ++i)
          matrix[i][0] = 0;
    }
  }
};

TEST_CASE("set-matrix-zeroes", "[0073]") {
  Solution sol;
  auto matrix = vector<vector<int>>{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  auto output = vector<vector<int>>{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
  sol.setZeroes(matrix);
  CHECK(matrix == output);
}

TEST_CASE("set-matrix-zeroes - 1", "[0073]") {
  Solution sol;
  auto matrix = vector<vector<int>>{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  auto output = vector<vector<int>>{{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
  sol.setZeroes(matrix);
  CHECK(matrix == output);
}

TEST_CASE("set-matrix-zeroes - 2", "[0073]") {
  Solution sol;
  auto matrix = vector<vector<int>>{
      {INT_MAX, 6, -7, 0}, {6, -8, -6, 0}, {2, -9, -6, -10}};
  auto output = vector<vector<int>>{{0, 0, 0, 0}, {0, 0, 0, 0}, {2, -9, -6, 0}};
  sol.setZeroes(matrix);
  CHECK(matrix == output);
}

TEST_CASE("set-matrix-zeroes - 3", "[0073]") {
  Solution sol;
  auto matrix = vector<vector<int>>{{8, 3, 6, 9, 7, 8, 0, 6},
                                     {0, 3, 7, 0, 0, 4, 3, 8},
                                     {5, 3, 6, 7, 1, 6, 2, 6},
                                     {8, 7, 2, 5, 0, 6, 4, 0},
                                     {0, 2, 9, 9, 3, 9, 7, 3}};
  auto output = vector<vector<int>>{{0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 3, 6, 0, 0, 6, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0}};
  sol.setZeroes(matrix);
  CHECK(matrix == output);
}
