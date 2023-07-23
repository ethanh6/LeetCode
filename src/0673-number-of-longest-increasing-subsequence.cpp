/*
**Notice** that the sequence has to be **strictly** increasing.

 **Example 1:**



     **Input:** nums = [1,3,5,4,7] **Output:** 2 **Explanation:** The two
longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

 **Example 2:**



     **Input:** nums = [2,2,2,2,2] **Output:** 5 **Explanation:** The length of
the longest increasing subsequence is 1, and there are 5 increasing subsequences
of length 1, so output 5.

 **Constraints:**

  * `1 <= nums.length <= 2000`
  * `-106 <= nums[i] <= 106`


*/

#include "leetcode.hpp"

class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> length(n, 1);
    vector<int> count(n, 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
          int newLen = length[j] + 1; // add one number behind nums[j]
          if (newLen > length[i]) {   // find LIC, update length[i] and count[i]
            length[i] = newLen;
            count[i] = count[j];
          } else if (newLen == length[i]) { // same length, only update count[i]
            count[i] += count[j];
          }
        }
      }
    }

    int maxLen = *max_element(length.begin(), length.end());
    int ans = 0;
    for (size_t i{}; i < n; ++i) {
      if (length[i] == maxLen)
        ans += count[i];
    }
    return ans;
  }
}

TEST_CASE("number-of-longest-increasing-subsequence", "[0673]") {
  Solution sol;
  CHECK(true);
}
