#include "leetcode.hpp"

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {

    auto comp = [&](const vector<int> &a, const vector<int> &b) {
      return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
    };

    sort(intervals.begin(), intervals.end(), comp);
    vector<vector<int>> output{intervals[0]};

    for (size_t i = 1; i < intervals.size(); ++i) {
      int start = intervals[i][0], end = intervals[i][1];

      if (output.back()[1] >= start) {
        output.back()[1] = max(output.back()[1], end);
      } else {
        output.push_back(intervals[i]);
      }
    }

    return output;
  }
};

TEST_CASE("merge-intervals", "[0056]") {
  Solution s;
  vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> ans{{1, 6}, {8, 10}, {15, 18}};

  REQUIRE(s.merge(intervals) == ans);
}

TEST_CASE("merge-intervals - 1", "[0056]") {
  Solution s;
  vector<vector<int>> intervals{{1, 4}, {4, 5}};
  vector<vector<int>> ans{{1, 5}};

  REQUIRE(s.merge(intervals) == ans);
}
