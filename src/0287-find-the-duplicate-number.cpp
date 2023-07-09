/*
**Example 1:**



     **Input:** nums = [1,3,4,2,2] **Output:** 2

 **Example 2:**



     **Input:** nums = [3,1,3,4,2] **Output:** 3

 **Constraints:**

  * `1 <= n <= 105`
  * `nums.length == n + 1`
  * `1 <= nums[i] <= n`
  * All the integers in `nums` appear only **once** except for **precisely one
integer** which appears **two or more** times.

 **Follow up:**

  * How can we prove that at least one duplicate number must exist in `nums`?
  * Can you solve the problem in linear runtime complexity?


*/

#include "leetcode.hpp"

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int slow = nums[0];
    int fast = nums[0];

    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    // here: slow == fast
    slow = nums[0];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    // here: slow == fast
    return slow;
  }
};

TEST_CASE("find-the-duplicate-number", "[0287]") {
  Solution sol;
  vector<int> nums{1, 3, 4, 2, 2};
  int output = 2;
  CHECK(sol.findDuplicate(nums) == output);
}

TEST_CASE("find-the-duplicate-number - 1", "[0287]") {
  Solution sol;
  vector<int> nums{3, 1, 3, 4, 2};
  int output = 3;
  CHECK(sol.findDuplicate(nums) == output);
}

TEST_CASE("find-the-duplicate-number - 2", "[0287]") {
  Solution sol;
  vector<int> nums{2, 2, 2, 2, 2};
  int output = 2;
  CHECK(sol.findDuplicate(nums) == output);
}
