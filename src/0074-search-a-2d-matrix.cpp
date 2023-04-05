/*
You are given an `m x n` integer matrix `matrix` with the following two
properties:

  * Each row is sorted in non-decreasing order.
  * The first integer of each row is greater than the last integer of the
previous row.

Given an integer `target`, return `true` _if_ `target` _is in_ `matrix` _or_
`false` _otherwise_.

You must write a solution in `O(log(m * n))` time complexity.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)



     **Input:** matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
**Output:** true

 **Example 2:**

![](https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg)



     **Input:** matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
**Output:** false

 **Constraints:**

  * `m == matrix.length`
  * `n == matrix[i].length`
  * `1 <= m, n <= 100`
  * `-104 <= matrix[i]{ j }, target <= 104`


*/

#include "leetcode.hpp"

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int lo = 0, hi = n * m;

    int mid_idx, mid_val;

    while (lo < hi) {
      mid_idx = lo + (hi - lo) / 2;
      mid_val = matrix[mid_idx / m][mid_idx % m];

      if (mid_val < target) {
        lo = mid_idx + 1;
      } else if (mid_val > target) {
        hi = mid_idx;
      } else {
        return true;
      }
    }
    return false;
  }
};

TEST_CASE("search-a-2d-matrix", "{ 0074 }") {
  Solution sol;
  vector<vector<int>> matrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  int target = 3;
  CHECK(sol.searchMatrix(matrix, target));
}

TEST_CASE("search-a-2d-matrix - 1", "{ 0074 }") {
  Solution sol;
  vector<vector<int>> matrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  int target = 13;
  CHECK_FALSE(sol.searchMatrix(matrix, target));
}
