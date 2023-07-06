/*
Given an integer array `nums`, find a subarray that has the largest product,
and return _the product_.

The test cases are generated so that the answer will fit in a **32-bit**
integer.

 **Example 1:**



     **Input:** nums = [2,3,-2,4] **Output:** 6 **Explanation:** [2,3] has the
largest product 6.

 **Example 2:**



     **Input:** nums = [-2,0,-1] **Output:** 0 **Explanation:** The result
cannot be 2, because [-2,-1] is not a subarray.

 **Constraints:**

  * `1 <= nums.length <= 2 * 104`
  * `-10 <= nums[i] <= 10`
  * The product of any prefix or suffix of `nums` is **guaranteed** to fit in a
**32-bit** integer.


*/

#include "leetcode.hpp"

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int max_so_far = nums[0];
    int min_so_far = nums[0];
    int result = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      int n = nums[i];
      int max_next = std::max({n, max_so_far * n, min_so_far * n});
      int min_next = std::min({n, max_so_far * n, min_so_far * n});

      max_so_far = max_next;
      min_so_far = min_next;

      result = std::max({result, max_so_far});
    }

    return result;
  }
};

TEST_CASE("maximum-product-subarray", "[0152]") {
  Solution sol;
  vector<int> nums = {2, 3, -2, 4};
  int output = 6;
  CHECK(sol.maxProduct(nums) == output);
}

TEST_CASE("maximum-product-subarray - 1", "[0152]") {
  Solution sol;
  vector<int> nums = {-2, 0, -1};
  int output = 0;
  CHECK(sol.maxProduct(nums) == output);
}
