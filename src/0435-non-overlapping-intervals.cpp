/*
Given an array of intervals `intervals` where `intervals[i] = [starti, endi]`,
return _the minimum number of intervals you need to remove to make the rest of
the intervals non-overlapping_.

 **Example 1:**



     **Input:** intervals = [[1,2],[2,3],[3,4],[1,3]] **Output:** 1
**Explanation:** [1,3] can be removed and the rest of the intervals are
non-overlapping.

 **Example 2:**



     **Input:** intervals = [[1,2],[1,2],[1,2]] **Output:** 2 **Explanation:**
You need to remove two [1,2] to make the rest of the intervals non-overlapping.

 **Example 3:**



     **Input:** intervals = [[1,2],[2,3]] **Output:** 0 **Explanation:** You
don't need to remove any of the intervals since they're already non-overlapping.

 **Constraints:**

  * `1 <= intervals.length <= 105`
  * `intervals[i].length == 2`
  * `-5 * 104 <= starti < endi <= 5 * 104`


*/

#include "leetcode.hpp"

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    auto comp = [&](const vector<int> &a, const vector<int> &b){
      return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    };

    sort(intervals.begin(), intervals.end(), comp);
    int prev = 0, count = 0;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[prev][1] <= intervals[i][0]) {
        // case 1
        prev = i;
      } else if (intervals[prev][1] >= intervals[i][1]) {
        // case 2
        count++;
        prev = i;
      } else if (intervals[prev][1] < intervals[i][1]) {
        // case 3
        count++;
      }
    }
    return count;
  }
};

TEST_CASE("non-overlapping-intervals", "[0435]") {
  Solution s;
  vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  REQUIRE(s.eraseOverlapIntervals(intervals) == 1);
}

TEST_CASE("non-overlapping-intervals - 1", "[0435]") {
  Solution s;
  vector<vector<int>> intervals = {{1, 2}, {1, 2}, {1, 2}};
  REQUIRE(s.eraseOverlapIntervals(intervals) == 2);
}

TEST_CASE("non-overlapping-intervals - 2", "[0435]") {
  Solution s;
  vector<vector<int>> intervals = {{1, 2}, {3, 4}};
  REQUIRE(s.eraseOverlapIntervals(intervals) == 0);
}
