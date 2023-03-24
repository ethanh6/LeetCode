/*
Given an integer array `nums` sorted in **non-decreasing** order, return _an
array of **the squares of each number** sorted in non-decreasing order_.

 **Example 1:**



     **Input:** nums = [-4,-1,0,3,10] **Output:** [0,1,9,16,100]
**Explanation:** After squaring, the array becomes [16,1,0,9,100].After sorting,
it becomes [0,1,9,16,100].

 **Example 2:**



     **Input:** nums = [-7,-3,2,3,11] **Output:** [4,9,9,49,121]

 **Constraints:**

  * `1 <= nums.length <= 104`
  * `-104 <= nums[i] <= 104`
  * `nums` is sorted in **non-decreasing** order.

 **Follow up:** Squaring each element and sorting the new array is very
trivial, could you find an `O(n)` solution using a different approach?


*/

#include "leetcode.hpp"

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {

    vector<int> output(nums.size(), 0);

    for (int i = nums.size() - 1, L = 0, R = nums.size() - 1; i >= 0; --i) {
      if (abs(nums[L]) > abs(nums[R])) {
        output[i] = pow(nums[L++], 2);
      } else {
        output[i] = pow(nums[R--], 2);
      }
    }
    return output;
  }
};

TEST_CASE("squares-of-a-sorted-array", "[0977]") {
  Solution s;
  vector<int> nums{-4, -1, 0, 3, 10};
  vector<int> output{0, 1, 9, 16, 100};
  REQUIRE(s.sortedSquares(nums) == output);
}

TEST_CASE("squares-of-a-sorted-array - 1", "[0977]") {
  Solution s;

  vector<int> nums{-7, -3, 2, 3, 11};
  vector<int> output{4, 9, 9, 49, 121};
  REQUIRE(s.sortedSquares(nums) == output);
}
