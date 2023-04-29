/*
A **permutation** of an array of integers is an arrangement of its members
into a sequence or linear order.

  * For example, for `arr = [1,2,3]`, the following are all the permutations of
`arr`: `[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1]`.

The **next permutation** of an array of integers is the next lexicographically
greater permutation of its integer. More formally, if all the permutations of
the array are sorted in one container according to their lexicographical
order, then the **next permutation** of that array is the permutation that
follows it in the sorted container. If such arrangement is not possible, the
array must be rearranged as the lowest possible order (i.e., sorted in
ascending order).

  * For example, the next permutation of `arr = [1,2,3]` is `[1,3,2]`.
  * Similarly, the next permutation of `arr = [2,3,1]` is `[3,1,2]`.
  * While the next permutation of `arr = [3,2,1]` is `[1,2,3]` because `[3,2,1]`
does not have a lexicographical larger rearrangement.

Given an array of integers `nums`, _find the next permutation of_ `nums`.

The replacement must be **[in place](http://en.wikipedia.org/wiki/In-
place_algorithm)** and use only constant extra memory.

 **Example 1:**



     **Input:** nums = [1,2,3] **Output:** [1,3,2]

 **Example 2:**



     **Input:** nums = [3,2,1] **Output:** [1,2,3]

 **Example 3:**



     **Input:** nums = [1,1,5] **Output:** [1,5,1]

 **Constraints:**

  * `1 <= nums.length <= 100`
  * `0 <= nums[i] <= 100`


*/

#include "leetcode.hpp"

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int n = nums.size(), k = 0, l = 0;

    // find the largest index k s.t. nums[k] < nums[k + 1]
    // aka the first digit that can be swapped
    for (k = n - 1; k > 0 && nums[k - 1] >= nums[k]; --k);

    // find the largest index l s.t. nums[k] < nums[l]
    // the bigger digit that appears after l
    if (k > 0) {
      for (l = n - 1; nums[l] <= nums[k - 1]; --l)
        ;

      swap(nums[k - 1], nums[l]);
    }

    // no valid k exists
    // meaning that the entire sequence is non-increasing
    reverse(nums.begin() + k, nums.end());
  }
};

TEST_CASE("next-permutation", "[0031]") {
  Solution sol;
  vector<int> nums = {1, 2, 3};
  vector<int> output = {1, 3, 2};
  sol.nextPermutation(nums);
  CHECK(nums == output);
}

TEST_CASE("next-permutation - 1", "[0031]") {
  Solution sol;
  vector<int> nums = {3, 2, 1};
  vector<int> output = {1, 2, 3};
  sol.nextPermutation(nums);
  CHECK(nums == output);
}

TEST_CASE("next-permutation - 2", "[0031]") {
  Solution sol;
  vector<int> nums = {1, 1, 5};
  vector<int> output = {1, 5, 1};
  sol.nextPermutation(nums);
  CHECK(nums == output);
}

TEST_CASE("next-permutation - 3", "[0031]") {
  Solution sol;
  vector<int> nums = {2, 3, 1};
  vector<int> output = {3, 1, 2};
  sol.nextPermutation(nums);
  CHECK(nums == output);
}
