#include "leetcode.hpp"

class Solution {
public:
  int minMeetingRooms(vector<vector<int>> &intervals) {
    vector<int> start_v, end_v;

    for(auto &i: intervals) {
      start_v.emplace_back(i[0]);
      end_v.emplace_back(i[1]);
    }

    std::sort(start_v.begin(), start_v.end());
    std::sort(end_v.begin(), end_v.end());

    int room_num = 0;

    for(int s{}, e{}; s < intervals.size(); ++s) {
      if(start_v[s] >= end_v[e]){ 
        // some meeting has ended before the start, time, so there must be a
        // room to be re-used
        e++;
      } else {
        // this start time happens before the earliest ending, so an additional
        // room must be used.
        room_num++;
      }
    }

    return room_num;

  }
};

TEST_CASE("meeting-rooms-ii", "[0759]") {
  Solution s;
  vector<vector<int>> intervals{{0, 30}, {5, 10}, {15, 20}};
  REQUIRE(s.minMeetingRooms(intervals) == 2);
}

TEST_CASE("meeting-rooms-ii - 1", "[0759]") {
  Solution s;
  vector<vector<int>> intervals{{7, 10}, {2, 4}};
  REQUIRE(s.minMeetingRooms(intervals) == 1);
}
