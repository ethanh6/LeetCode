/*
An image is represented by an `m x n` integer grid `image` where `image[i][j]`
represents the pixel value of the image.

You are also given three integers `sr`, `sc`, and `color`. You should perform
a **flood fill** on the image starting from the pixel `image[sr][sc]`.

To perform a **flood fill** , consider the starting pixel, plus any pixels
connected **4-directionally** to the starting pixel of the same color as the
starting pixel, plus any pixels connected **4-directionally** to those pixels
(also with the same color), and so on. Replace the color of all of the
aforementioned pixels with `color`.

Return _the modified image after performing the flood fill_.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/06/01/flood1-grid.jpg)



     **Input:** image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
**Output:** [[2,2,2],[2,2,0],[2,0,1]] **Explanation:** From the center of the
image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels
connected by a path of the same color as the starting pixel (i.e., the blue
pixels) are colored with the new color.Note the bottom corner is not colored 2,
because it is not 4-directionally connected to the starting pixel.

 **Example 2:**



     **Input:** image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0 **Output:**
[[0,0,0],[0,0,0]] **Explanation:** The starting pixel is already colored 0, so
no changes are made to the image.

 **Constraints:**

  * `m == image.length`
  * `n == image[i].length`
  * `1 <= m, n <= 50`
  * `0 <= image[i][j], color < 216`
  * `0 <= sr < m`
  * `0 <= sc < n`


*/

#include "leetcode.hpp"

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<vector<int>> q;
    int n = image.size(), m = image[0].size();

    if (color == image[sr][sc]) {
      return image;
    }

    auto original_color = image[sr][sc];

    q.push(vector<int>{sr, sc});

    while (q.size()) {
      // pop the current node
      auto cur = q.front();
      q.pop();

      // fill the color of the current index
      image[cur[0]][cur[1]] = color;

      // expand to 4-direction
      for (const auto &dir : direction) {
        int new_i = cur[0] + dir[0];
        int new_j = cur[1] + dir[1];
        if (0 <= new_i && new_i < n && 0 <= new_j && new_j < m &&
            image[new_i][new_j] == original_color) {
          q.push(vector<int>{new_i, new_j});
        }
      }
    }

    return image;
  }
};

TEST_CASE("flood-fill", "[0733]") {
  Solution sol;
  vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  int sr = 1, sc = 1;
  int color = 2;
  vector<vector<int>> result = {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}};
  CHECK(sol.floodFill(image, sr, sc, color) == result);
}

TEST_CASE("flood-fill - 1", "[0733]") {
  Solution sol;
  vector<vector<int>> image = {{0, 0, 0}, {0, 0, 0}};
  int sr = 0, sc = 0;
  int color = 0;
  vector<vector<int>> result = {{0, 0, 0}, {0, 0, 0}};

  CHECK(sol.floodFill(image, sr, sc, color) == result);
}
