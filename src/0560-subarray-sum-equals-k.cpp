/*
Given an array of integers `nums` and an integer `k`, return _the total number
of subarrays whose sum equals to_ `k`.

A subarray is a contiguous **non-empty** sequence of elements within an array.

 **Example 1:**



     **Input:** nums = [1,1,1], k = 2 **Output:** 2

 **Example 2:**



     **Input:** nums = [1,2,3], k = 3 **Output:** 2

 **Constraints:**

  * `1 <= nums.length <= 2 * 104`
  * `-1000 <= nums[i] <= 1000`
  * `-107 <= k <= 107`


*/

#include "leetcode.hpp"

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int ans = 0;
    unordered_map<int, int> m{{0, 1}}; // accumulated_sum -> occurance
    for (int i = 0, s = 0; i < nums.size(); ++i) {
      s += nums[i];

      if (m.count(s - k) != 0) {
        ans += m[s - k];
      }

      m[s] += 1;
    }
    return ans;
  }
};

TEST_CASE("subarray-sum-equals-k", "[0560]") {
  Solution s;
  vector<int> nums = {1, 1, 1};
  int k = 2;
  REQUIRE(s.subarraySum(nums, k) == 2);
}

TEST_CASE("subarray-sum-equals-k - 1", "[0560]") {
  Solution s;
  vector<int> nums = {1, 2, 3};
  int k = 3;
  REQUIRE(s.subarraySum(nums, k) == 2);
}

TEST_CASE("subarray-sum-equals-k - 2", "[0560]") {
  Solution s;
  vector<int> nums = {1, 2, 1, 2, 1};
  int k = 3;
  REQUIRE(s.subarraySum(nums, k) == 4);
}

TEST_CASE("subarray-sum-equals-k - 3", "[0560]") {
  Solution s;
  vector<int> nums = {1, -1, 0};
  int k = 0;
  REQUIRE(s.subarraySum(nums, k) == 3);
}
