#include "leetcode.hpp"

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> res;
    unordered_map<int, int> seen;
    for (auto i = 0; i < nums.size(); ++i) {
      if (seen.count(target - nums[i]) != 0) {
        res.emplace_back(seen[target - nums[i]]);
        res.emplace_back(i);
      } else {
        seen[nums[i]] = i;
      }
    }

    return res;
  }
};

TEST_CASE("two-sum", "[0001]") {
  Solution s;
  vector<int> input {2, 7, 11, 15};
  REQUIRE(s.twoSum(input, 9) == vector<int>{0, 1});
  REQUIRE(s.twoSum(input, 26) == vector<int>{2, 3});
}
