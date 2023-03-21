#include "leetcode.hpp"

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());
      for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i-1][1] > intervals[i][0]) {
          return false;
        }
      }
      return true;
    }
};

TEST_CASE("meeting-rooms", "[0252]") {
  Solution s;
  vector<vector<int>> input {{0, 30}, {5, 10}, {15, 20}};
  REQUIRE_FALSE(s.canAttendMeetings(input));

  input = {{7, 10}, {2, 4}};
  REQUIRE(s.canAttendMeetings(input));
}
