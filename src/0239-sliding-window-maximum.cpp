/*
Return _the max sliding window_.

 **Example 1:**



     **Input:** nums = [1,3,-1,-3,5,3,6,7], k = 3 **Output:** [3,3,5,5,6,7]
**Explanation:** Window position                Max--------------- -----[1  3
-1] -3  5  3  6  7       **3** 1 [3  -1  -3] 5  3  6  7       **3** 1  3 [-1  -3
5] 3  6  7      **5** 1  3  -1 [-3  5  3] 6  7       **5** 1  3  -1  -3 [5  3 6]
7       **6** 1  3  -1  -3  5 [3  6  7]      **7**

 **Example 2:**



     **Input:** nums = [1], k = 1 **Output:** [1]

 **Constraints:**

  * `1 <= nums.length <= 105`
  * `-104 <= nums[i] <= 104`
  * `1 <= k <= nums.length`


*/

#include "leetcode.hpp"

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();
    if (k == 1) {
      return nums;
    }

    vector<int> left(n), right(n);
    left.front() = nums.front();
    right.back() = nums.back();

    // build left and right
    for (int i = 1; i < n; ++i) {
      // build left
      if (i % k == 0) {
        left[i] = nums[i]; // block start
      } else {
        left[i] = max(left[i - 1], nums[i]);
      }

      // build right
      int j = n - i - 1;
      if ((j + 1) % k == 0) {
        right[j] = nums[j];
      } else {
        right[j] = max(right[j + 1], nums[j]);
      }
    }

    vector<int> output(n - k + 1);
    for (int i = 0; i < output.size(); ++i) {
      output[i] = max(left[i + k - 1], right[i]);
    }

    return output;
  }
};

TEST_CASE("sliding-window-maximum", "[0239]") {
  Solution s;
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  REQUIRE(s.maxSlidingWindow(nums, k) == vector<int>{3, 3, 5, 5, 6, 7});
}

TEST_CASE("sliding-window-maximum - 1", "[0239]") {
  Solution s;
  vector<int> nums = {-7, -8, 7, 5, 7, 1, 6, 0};
  int k = 4;
  REQUIRE(s.maxSlidingWindow(nums, k) == vector<int>{7, 7, 7, 7, 7});
}
