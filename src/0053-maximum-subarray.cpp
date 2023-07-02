/*
Given an integer array `nums`, find the subarray with the largest sum, and
return _its sum_.

 **Example 1:**



     **Input:** nums = [-2,1,-3,4,-1,2,1,-5,4] **Output:** 6 **Explanation:**
The subarray [4,-1,2,1] has the largest sum 6.

 **Example 2:**



     **Input:** nums = [1] **Output:** 1 **Explanation:** The subarray [1] has
the largest sum 1.

 **Example 3:**



     **Input:** nums = [5,4,-1,7,8] **Output:** 23 **Explanation:** The subarray
[5,4,-1,7,8] has the largest sum 23.

 **Constraints:**

  * `1 <= nums.length <= 105`
  * `-104 <= nums[i] <= 104`

 **Follow up:** If you have figured out the `O(n)` solution, try coding
another solution using the **divide and conquer** approach, which is more
subtle.


*/

#include "leetcode.hpp"

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();

    vector<int> dp(n);
    dp[0] = nums[0];

    // dp[i] is the maxSubArray that 
    // ends in nums[i] containing nums[i]
    for (int i = 1; i < n; ++i) {
      dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
    }

    return *max_element(dp.begin(), dp.end());
  }
};

TEST_CASE("maximum-subarray", "[0053]") {
  Solution sol;
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int output = 6;
  CHECK(sol.maxSubArray(nums) == output);
}

TEST_CASE("maximum-subarray - 1", "[0053]") {
  Solution sol;
  vector<int> nums = {1};
  int output = 1;
  CHECK(sol.maxSubArray(nums) == output);
}

TEST_CASE("maximum-subarray - 2", "[0053]") {
  Solution sol;
  vector<int> nums = {5, 4, -1, 7, 8};
  int output = 23;
  CHECK(sol.maxSubArray(nums) == output);
}
