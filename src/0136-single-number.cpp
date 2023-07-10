/*
**Example 1:**



     **Input:** nums = [2,2,1] **Output:** 1

 **Example 2:**



     **Input:** nums = [4,1,2,1,2] **Output:** 4

 **Example 3:**



     **Input:** nums = [1] **Output:** 1

 **Constraints:**

  * `1 <= nums.length <= 3 * 104`
  * `-3 * 104 <= nums[i] <= 3 * 104`
  * Each element in the array appears twice except for one element which appears
only once.


*/

#include "leetcode.hpp"

class Solution0 {
public:
  int singleNumber(vector<int> &nums) {
    int res = 0;
    for (const auto &n : nums)
      res ^= n;
    return res;
  }
};

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    return std::accumulate(nums.begin(), nums.end(), 0,
                           [&](int a, int b) { return a ^ b; });
  }
};

TEST_CASE("single-number", "[0136]") {
  Solution sol;
  vector<int> nums = {2, 2, 1};
  int output = 1;
  CHECK(sol.singleNumber(nums) == output);
}

TEST_CASE("single-number - 1", "[0136]") {
  Solution sol;
  vector<int> nums = {4, 1, 2, 1, 2};
  int output = 4;
  CHECK(sol.singleNumber(nums) == output);
}

TEST_CASE("single-number - 2", "[0136]") {
  Solution sol;
  vector<int> nums = {1};
  int output = 1;
  CHECK(sol.singleNumber(nums) == output);
}
