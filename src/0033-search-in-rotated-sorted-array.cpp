/*
There is an integer array `nums` sorted in ascending order (with **distinct**
values).

Prior to being passed to your function, `nums` is **possibly rotated** at an
unknown pivot index `k` (`1 <= k < nums.length`) such that the resulting array
is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (
**0-indexed** ). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot
index `3` and become `[4,5,6,7,0,1,2]`.

Given the array `nums` **after** the possible rotation and an integer
`target`, return _the index of_`target` _if it is in_`nums` _, or_`-1` _if it
is not in_`nums`.

You must write an algorithm with `O(log n)` runtime complexity.

 **Example 1:**



     **Input:** nums = [4,5,6,7,0,1,2], target = 0 **Output:** 4

 **Example 2:**



     **Input:** nums = [4,5,6,7,0,1,2], target = 3 **Output:** -1

 **Example 3:**



     **Input:** nums = [1], target = 0 **Output:** -1

 **Constraints:**

  * `1 <= nums.length <= 5000`
  * `-104 <= nums[i] <= 104`
  * All values of `nums` are **unique**.
  * `nums` is an ascending array that is possibly rotated.
  * `-104 <= target <= 104`


*/

#include "leetcode.hpp"

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int lo = 0, hi = nums.size();
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      int n = 0;

      // update n on the fly
      if (nums[0] <= target == nums[0] <= nums[mid]) {
        n = nums[mid];
      } else if (nums[mid] < nums[0]) {
        n = INT_MAX;
      } else {
        n = INT_MIN;
      }

      if (n > target) {
        hi = mid;
      } else if (n < target) {
        lo = mid + 1;
      } else if (n == target) {
        return mid;
      }
    }

    return -1;
  }
};

TEST_CASE("search-in-rotated-sorted-array", "[0033]") {
  Solution sol;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  CHECK(sol.search(nums, target) == 4);

  nums = {4, 5, 6, 7, 0, 1, 2};
  target = 3;
  CHECK(sol.search(nums, target) == -1);

  nums = {1};
  target = 0;
  CHECK(sol.search(nums, target) == -1);

  nums = {1, 3};
  target = 1;
  CHECK(sol.search(nums, target) == 0);
}
