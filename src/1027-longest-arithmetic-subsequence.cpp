/*
Given an array `nums` of integers, return _the length of the longest
arithmetic subsequence in_ `nums`.

 **Note** that:

  * A **subsequence** is an array that can be derived from another array by
deleting some or no elements without changing the order of the remaining
elements.
  * A sequence `seq` is arithmetic if `seq[i + 1] - seq[i]` are all the same
value (for `0 <= i < seq.length - 1`).

 **Example 1:**



     **Input:** nums = [3,6,9,12] **Output:** 4 **Explanation:** The whole array
is an arithmetic sequence with steps of length = 3.

 **Example 2:**



     **Input:** nums = [9,4,7,2,10] **Output:** 3 **Explanation:** The longest
arithmetic subsequence is [4,7,10].

 **Example 3:**



     **Input:** nums = [20,1,15,3,10,5,8] **Output:** 4 **Explanation:** The
longest arithmetic subsequence is [20,15,10,5].

 **Constraints:**

  * `2 <= nums.length <= 1000`
  * `0 <= nums[i] <= 500`


*/

#include "leetcode.hpp"
class Solution {
public:
  int longestArithSeqLength(vector<int> &nums) {
    int max_length = 0;
    vector<unordered_map<int, int>> dp(nums.size()); // vector of (diff -> size)
    for (int r = 0; r < nums.size(); ++r) {
      for (int l = 0; l < r; ++l) {
        int diff = nums[r] - nums[l];
        dp[r][diff] = dp[l].count(diff) == 0 ? 2 : dp[l][diff] + 1;
        max_length = max(max_length, dp[r][diff]);
      }
    }
    return max_length;
  }
};

TEST_CASE("longest-arithmetic-subsequence", "[1027]") {
  Solution sol;
  vector<int> input{3, 6, 9, 12};
  CHECK(sol.longestArithSeqLength(input) == 4);
}

TEST_CASE("longest-arithmetic-subsequence - 1", "[1027]") {
  Solution sol;
  vector<int> input{9, 4, 7, 2, 10};
  CHECK(sol.longestArithSeqLength(input) == 3);
}

TEST_CASE("longest-arithmetic-subsequence - 2", "[1027]") {
  Solution sol;
  vector<int> input{20, 1, 15, 3, 10, 5, 8};
  CHECK(sol.longestArithSeqLength(input) == 4);
}
