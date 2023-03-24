/*
Given an integer array `nums`, move all `0`'s to the end of it while
maintaining the relative order of the non-zero elements.

 **Note** that you must do this in-place without making a copy of the array.

 **Example 1:**



     **Input:** nums = [0,1,0,3,12] **Output:** [1,3,12,0,0]

 **Example 2:**



     **Input:** nums = [0] **Output:** [0]

 **Constraints:**

  * `1 <= nums.length <= 104`
  * `-231 <= nums[i] <= 231 - 1`

 **Follow up:** Could you minimize the total number of operations done?


*/

#include "leetcode.hpp"

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    for (int nz = 0, i = 0; i < nums.size(); ++i) {
      if(nums[i] != 0) {
        swap(nums[i], nums[nz++]);
      }
    }
  }
};

TEST_CASE("move-zeroes", "[0283]") {
  Solution s;
  vector<int> nums{0, 1, 0, 3, 12};
  vector<int> output{1, 3, 12, 0, 0};
  s.moveZeroes(nums);
  REQUIRE(nums == output);
}

TEST_CASE("move-zeroes - 1", "[0283]") {
  Solution s;
  vector<int> nums{0};
  vector<int> output{0};
  s.moveZeroes(nums);
  REQUIRE(nums == output);
}

TEST_CASE("move-zeroes - 2", "[0283]") {
  Solution s;
  vector<int> nums{0, 1, 0, 2, 3, 0, 5};
  vector<int> output{1, 2, 3, 5, 0, 0, 0};
  s.moveZeroes(nums);
  REQUIRE(nums == output);
}

TEST_CASE("move-zeroes - 3", "[0283]") {
  Solution s;
  vector<int> nums{1};
  vector<int> output{1};
  s.moveZeroes(nums);
  REQUIRE(nums == output);
}

TEST_CASE("move-zeroes - 4", "[0283]") {
  Solution s;
  vector<int> nums{1, 0};
  vector<int> output{1, 0};
  s.moveZeroes(nums);
  REQUIRE(nums == output);
}
