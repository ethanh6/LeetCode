/*
You are given an integer array `nums`. You are initially positioned at the
array's **first index** , and each element in the array represents your
maximum jump length at that position.

Return `true` _if you can reach the last index, or_`false` _otherwise_.

 **Example 1:**



     **Input:** nums = [2,3,1,1,4] **Output:** true **Explanation:** Jump 1 step
from index 0 to 1, then 3 steps to the last index.

 **Example 2:**



     **Input:** nums = [3,2,1,0,4] **Output:** false **Explanation:** You will
always arrive at index 3 no matter what. Its maximum jump length is 0, which
makes it impossible to reach the last index.

 **Constraints:**

  * `1 <= nums.length <= 104`
  * `0 <= nums[i] <= 105`


*/

#include "leetcode.hpp"

class Solution0 {
public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();

    int last_reachable = n - 1;

    for (int i = n - 2; i >= 0; --i) {
      if (i + nums[i] >= last_reachable)
        last_reachable = i;
    }

    return last_reachable == 0;
  }
};

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    vector<bool> dp(n, false);
    dp[n - 1] = true;

    for (int i = n - 2; i >= 0; --i) {
      // can only jump to index (n - 1)
      int furthestJump = min(i + nums[i], n - 1);

      for (int j = i + 1; j <= furthestJump; ++j) {
        if (dp[j]) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[0];
  }
};

TEST_CASE("jump-game", "[0055]") {
  Solution sol;
  vector<int> nums = {2, 3, 1, 1, 4};
  CHECK(sol.canJump(nums));
}

TEST_CASE("jump-game - 1", "[0055]") {
  Solution sol;
  vector<int> nums = {3, 2, 1, 0, 4};
  CHECK_FALSE(sol.canJump(nums));
}

TEST_CASE("jump-game - 2", "[0055]") {
  Solution sol;
  vector<int> nums = {1, 2};
  CHECK(sol.canJump(nums));
}

TEST_CASE("jump-game - 3", "[0055]") {
  Solution sol;
  vector<int> nums = {0};
  CHECK(sol.canJump(nums));
}

TEST_CASE("jump-game - 4", "[0055]") {
  Solution sol;
  vector<int> nums = {2, 5, 0, 0};
  CHECK(sol.canJump(nums));
}
