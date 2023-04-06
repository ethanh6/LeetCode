/*
Suppose an array of length `n` sorted in ascending order is **rotated**
between `1` and `n` times. For example, the array `nums = [0,1,2,4,5,6,7]`
might become:

  * `[4,5,6,7,0,1,2]` if it was rotated `4` times.
  * `[0,1,2,4,5,6,7]` if it was rotated `7` times.

Notice that **rotating** an array `[a[0], a[1], a[2], ..., a[n-1]]` 1 time
results in the array `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Given the sorted rotated array `nums` of **unique** elements, return _the
minimum element of this array_.

 **Example 1:**



     **Input:** nums = [3,4,5,1,2] **Output:** 1 **Explanation:** The original
array was [1,2,3,4,5] rotated 3 times.

 **Example 2:**



     **Input:** nums = [4,5,6,7,0,1,2] **Output:** 0 **Explanation:** The
original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

 **Example 3:**



     **Input:** nums = [11,13,15,17] **Output:** 11 **Explanation:** The
original array was [11,13,15,17] and it was rotated 4 times.

**Constraints:**

  * `n == nums.length`
  * `1 <= n <= 5000`
  * `-5000 <= nums[i] <= 5000`
  * All the integers of `nums` are **unique**.
  * `nums` is sorted and rotated between `1` and `n` times.


*/

#include "leetcode.hpp"

class Solution {
public:
  int findMin(vector<int> &nums) {
    int lo = 0, hi = nums.size() - 1;

    if (nums[0] < nums.back()) 
      return nums[0];


    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;

      if (nums[mid] > nums[mid + 1]) 
        return nums[mid + 1];

      if (nums[mid - 1] > nums[mid]) 
        return nums[mid];


      if (nums[mid] > nums[hi]) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }

    return nums[lo];
  }
};

class Solution1 {
public:
  int findMin(vector<int> &nums) {
    int lo = 0, hi = nums.size() - 1;

    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;

      if (nums[mid] < nums[hi]) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }

    return nums[lo];
  }
};

TEST_CASE("find-minimum-in-rotated-sorted-array", "[0153]") {
  Solution1 sol;
  vector<int> nums = {4, 5, 6, 1, 2, 3};
  int output = 1;
  CHECK(sol.findMin(nums) == output);
}

TEST_CASE("find-minimum-in-rotated-sorted-array - 1", "[0153]") {
  Solution1 sol;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int output = 0;
  CHECK(sol.findMin(nums) == output);
}

TEST_CASE("find-minimum-in-rotated-sorted-array - 2", "[0153]") {
  Solution1 sol;
  vector<int> nums = {11, 13, 15, 17};
  int output = 11;
  CHECK(sol.findMin(nums) == output);
}
