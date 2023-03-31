/*
Given an `m x n` `matrix`, return _all elements of the_ `matrix` _in spiral
order_.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg)

     **Input:** matrix = [[1,2,3],[4,5,6],[7,8,9]] **Output:**
[1,2,3,6,9,8,7,4,5]

 **Example 2:**

![](https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg)



     **Input:** matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]] **Output:**
[1,2,3,4,8,12,11,10,9,5,6,7]

 **Constraints:**

  * `m == matrix.length`
  * `n == matrix[i].length`
  * `1 <= m, n <= 10`
  * `-100 <= matrix[i][j] <= 100`


*/

#include "leetcode.hpp"

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    // direction matrix
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<int> res;

    int nr = matrix.size();
    int nc = matrix[0].size();
    if (nr == 0 || nc == 0) {
      return res;
    }

    // initial position is one step left to the first element
    // so num of columns is nc, num of row is nr - 1
    vector<int> nSteps{nc, nr - 1};

    int iDir = 0;        // index of direction.
    int ir = 0, ic = -1; // initial position

    while (nSteps[iDir % 2]) {
      for (int i = 0; i < nSteps[iDir % 2]; ++i) {
        // update coordinate and push
        ir += dirs[iDir][0];
        ic += dirs[iDir][1];
        res.push_back(matrix[ir][ic]);
      }
      nSteps[iDir % 2]--;

      // update direction
      iDir = (iDir + 1) % 4;
    }
    return res;
  }
};

TEST_CASE("spiral-matrix", "[0054]") {
  Solution sol;
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> output = {1, 2, 3, 6, 9, 8, 7, 4, 5};
  CHECK(sol.spiralOrder(matrix) == output);
}
