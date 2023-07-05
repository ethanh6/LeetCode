/*
Given an integer array `nums`, return `true` _if you can partition the array
into two subsets such that the sum of the elements in both subsets is equal
or_`false` _otherwise_.

 **Example 1:**



     **Input:** nums = [1,5,11,5] **Output:** true **Explanation:** The array
can be partitioned as [1, 5, 5] and [11].

 **Example 2:**



     **Input:** nums = [1,2,3,5] **Output:** false **Explanation:** The array
cannot be partitioned into equal sum subsets.

 **Constraints:**

  * `1 <= nums.length <= 200`
  * `1 <= nums[i] <= 100`


*/

#include "leetcode.hpp"

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int total = 0;
    for (const auto &x : nums) {
      total += x;
    }

    if (total % 2 == 1)
      return false;

    int half = total / 2;
    int n = nums.size();

    // dimension: (nums.size() + 1) x (half + 1)
    vector<vector<bool>> dp(n + 1, vector<bool>(half + 1, false));

    // base cases
    dp[0][0] = true;

    for (int c = 1; c < half + 1; ++c)
      dp[0][c] = false;

    for (int r = 1; r < n + 1; ++r)
      dp[r][0] = true;

    // fill in the table
    for (int r = 1; r < n + 1; ++r) {
      for (int c = 1; c < half + 1; ++c) {
        // make sure no out-of-bounds error
        if (c >= nums[r - 1])
          dp[r][c] = dp[r - 1][c] || dp[r - 1][c - nums[r - 1]];
        else
          dp[r][c] = dp[r - 1][c];
      }
    }

    return dp.back().back();
  }
};

TEST_CASE("partition-equal-subset-sum", "[0416]") {
  Solution sol;
  vector<int> nums = {1, 5, 11, 5};
  CHECK(sol.canPartition(nums));
}

TEST_CASE("partition-equal-subset-sum - 1", "[0416]") {
  Solution sol;
  vector<int> nums = {1, 2, 3, 5};
  CHECK_FALSE(sol.canPartition(nums));
}

TEST_CASE("partition-equal-subset-sum - 2", "[0416]") {
  Solution sol;
  vector<int> nums = {3, 4, 2, 1};
  CHECK(sol.canPartition(nums));
}

TEST_CASE("partition-equal-subset-sum - 3", "[0416]") {
  Solution sol;
  vector<int> nums = {1, 2, 5};
  CHECK_FALSE(sol.canPartition(nums));
}
