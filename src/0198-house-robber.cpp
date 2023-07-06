/*
You are a professional robber planning to rob houses along a street. Each
house has a certain amount of money stashed, the only constraint stopping you
from robbing each of them is that adjacent houses have security systems
connected and **it will automatically contact the police if two adjacent
houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house,
return _the maximum amount of money you can rob tonight **without alerting the
police**_.

 **Example 1:**



     **Input:** nums = [1,2,3,1] **Output:** 4 **Explanation:** Rob house 1
(money = 1) and then rob house 3 (money = 3).Total amount you can rob = 1 + 3
= 4.

 **Example 2:**



     **Input:** nums = [2,7,9,3,1] **Output:** 12 **Explanation:** Rob house 1
(money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).Total amount
you can rob = 2 + 9 + 1 = 12.

 **Constraints:**

  * `1 <= nums.length <= 100`
  * `0 <= nums[i] <= 400`


*/

#include "leetcode.hpp"

class Solution0 {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();

    // definition
    // dp[i] := rob(nums[:i]), not including index i
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i < n + 1; ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }

    return dp.back();
  }
};

class Solution {
public:
  int rob(vector<int> &nums) {
    int a = 0, b = 0;

    for (const auto &n : nums) {
      int next_b = max(b, a + n);
      a = b;
      b = next_b;
    }

    return b;
  }
};

TEST_CASE("house-robber", "[0198]") {
  Solution sol;
  vector<int> nums = {1, 2, 3, 1};
  int output{4};
  CHECK(sol.rob(nums) == output);
}

TEST_CASE("house-robber - 1", "[0198]") {
  Solution sol;
  vector<int> nums = {2, 7, 9, 3, 1};
  int output{12};
  CHECK(sol.rob(nums) == output);
}
