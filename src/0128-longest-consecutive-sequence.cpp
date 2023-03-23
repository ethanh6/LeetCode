#include "leetcode.hpp"

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {

    unordered_set<int> s(nums.begin(), nums.end());
    int cur, streak, ans = 0;

    for (auto &n: nums) {
      if (s.count(n - 1) > 0) {
        continue;
      }

      cur = n;
      streak = 1;

      while (s.count(cur + 1) > 0) {
        cur++;
        streak++;
      }

      ans = max(ans, streak);
    }

    return ans;
  }
};

TEST_CASE("longest-consecutive-sequence", "[0128]") {
  Solution s;
  vector<int> input{100, 4, 200, 1, 3, 2};
  REQUIRE(s.longestConsecutive(input) == 4);


  input = {0,3,7,2,5,8,4,6,0,1};
  REQUIRE(s.longestConsecutive(input) == 9);

  input = {};
  REQUIRE(s.longestConsecutive(input) == 0);
}
