/*
Given an integer array `nums`, return _the length of the longest **strictly
increasing**_ _ **subsequence**_.

 **Example 1:**



     **Input:** nums = [10,9,2,5,3,7,101,18] **Output:** 4 **Explanation:** The
longest increasing subsequence is [2,3,7,101], therefore the length is 4.

 **Example 2:**



     **Input:** nums = [0,1,0,3,2,3] **Output:** 4

 **Example 3:**



     **Input:** nums = [7,7,7,7,7,7,7] **Output:** 1

 **Constraints:**

  * `1 <= nums.length <= 2500`
  * `-104 <= nums[i] <= 104`


*/

#include "leetcode.hpp"

class Solution_0 {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();

    if (n <= 1)
      return n;

    // dp[i] := LIC that ends with nums[i]
    vector<int> dp(n, 1);

    for (int i = 0; i < n; ++i) {
      int max_candidate = 0;

      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          max_candidate = max(max_candidate, dp[j]);
        }
      }

      dp[i] = max_candidate + 1;
    }

    return *max_element(dp.begin(), dp.end());
  }
};

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> dp;
    for (const auto &n : nums) {
      auto it = lower_bound(dp.begin(), dp.end(), n);
      if (it == dp.end())
        dp.push_back(n);
      else
        *it = n;
    }
    return dp.size();
  }
};

TEST_CASE("longest-increasing-subsequence", "[0300]") {
  Solution sol;
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  int output = 4;
  CHECK(sol.lengthOfLIS(nums) == output);
}

TEST_CASE("longest-increasing-subsequence - 1", "[0300]") {
  Solution sol;
  vector<int> nums = {7, 7, 7, 7, 7, 7, 7};
  int output = 1;
  CHECK(sol.lengthOfLIS(nums) == output);
}

TEST_CASE("longest-increasing-subsequence - 2", "[0300]") {
  Solution sol;
  vector<int> nums = {0, 1, 0, 3, 2, 3};
  int output = 4;
  CHECK(sol.lengthOfLIS(nums) == output);
}
