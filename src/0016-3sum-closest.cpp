/*
Given an integer array `nums` of length `n` and an integer `target`, find
three integers in `nums` such that the sum is closest to `target`.

Return _the sum of the three integers_.

You may assume that each input would have exactly one solution.

 **Example 1:**



     **Input:** nums = [-1,2,1,-4], target = 1 **Output:** 2 **Explanation:**
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

 **Example 2:**



     **Input:** nums = [0,0,0], target = 1 **Output:** 0 **Explanation:** The
sum that is closest to the target is 0. (0 + 0 + 0 = 0).

 **Constraints:**

  * `3 <= nums.length <= 500`
  * `-1000 <= nums[i] <= 1000`
  * `-104 <= target <= 104`


*/

#include "leetcode.hpp"

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());

    int diff = INT_MAX, lo, hi, sum;

    for (int i = 0; i < nums.size(); ++i) {
      lo = i + 1, hi = nums.size() - 1;
      while (lo < hi) {
        sum = nums[i] + nums[lo] + nums[hi];
        if (abs(target - sum) < abs(diff)) {
          diff = target - sum;
        }

        if (sum < target) {
          lo++;
        } else if (sum > target) {
          hi--;
        } else {
          // if sum == target
          return target;
        }
      }
    }

    return target - diff;
  }
};

TEST_CASE("3sum-closest", "[0016]") {
  Solution s;
  vector<int> nums{-1, 2, 1, -4};
  REQUIRE(s.threeSumClosest(nums, 1) == 2);
}

TEST_CASE("3sum-closest - 1", "[0016]") {
  Solution s;
  vector<int> nums{0, 0, 0};
  REQUIRE(s.threeSumClosest(nums, 1) == 0);
}
