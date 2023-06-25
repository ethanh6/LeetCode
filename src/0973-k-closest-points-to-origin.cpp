/*
Given an array of `points` where `points[i] = [xi, yi]` represents a point on
the **X-Y** plane and an integer `k`, return the `k` closest points to the
origin `(0, 0)`.

The distance between two points on the **X-Y** plane is the Euclidean distance
(i.e., `√(x1 - x2)2 + (y1 - y2)2`).

You may return the answer in **any order**. The answer is **guaranteed** to be
**unique** (except for the order that it is in).

 **Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/03/closestplane1.jpg)



     **Input:** points = [[1,3],[-2,2]], k = 1 **Output:** [[-2,2]]
**Explanation:** The distance between (1, 3) and the origin is sqrt(10).The
distance between (-2, 2) and the origin is sqrt(8).Since sqrt(8) < sqrt(10),
(-2, 2) is closer to the origin.We only want the closest k = 1 points from the
origin, so the answer is just [[-2,2]].

 **Example 2:**



     **Input:** points = [[3,3],[5,-1],[-2,4]], k = 2 **Output:** [[3,3],[-2,4]]
**Explanation:** The answer [[-2,4],[3,3]] would also be accepted.

 **Constraints:**

  * `1 <= k <= points.length <= 104`
  * `-104 < xi, yi < 104`


*/

#include "leetcode.hpp"

class Solution0 {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {

    sort(points.begin(), points.end(),
         [](const vector<int> &v1, const vector<int> &v2) -> bool {
           return v1[0] * v1[0] + v1[1] * v1[1] < v2[0] * v2[0] + v2[1] * v2[1];
         });

    vector<vector<int>> res;

    // append first k elements in points to res
    res.insert(res.end(), points.begin(), points.begin() + k);

    return res;
  }
};

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    auto euclidian = [](vector<int> &p) { return p[0] * p[0] + p[1] * p[1]; };

    // build a min-heap
    auto comp = [&](vector<int> &a, vector<int> &b) {
      return euclidian(a) > euclidian(b);
    };
    make_heap(points.begin(), points.end(), comp);

    for (int i = 0; i < k; ++i) {
      pop_heap(points.begin(), points.end() - i, comp);
    }

    return vector<vector<int>>(points.end() - k, points.end());
  }
};

TEST_CASE("k-closest-points-to-origin", "[0973]") {
  vector<vector<int>> points = {{1, 3}, {-2, 2}};
  vector<vector<int>> output = {{-2, 2}};
  Solution sol;
  CHECK(sol.kClosest(points, 1) == output);
}

TEST_CASE("k-closest-points-to-origin - 1", "[0973]") {
  vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
  vector<vector<int>> output = {{-2, 4}, {3, 3}};
  Solution sol;
  CHECK(sol.kClosest(points, 2) == output);
}
