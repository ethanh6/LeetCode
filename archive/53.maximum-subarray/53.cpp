#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "assert.h"

using namespace std;

class Solution {
public:

  // slightly optimized solution
  int maxSubArray_1(vector<int>& nums) {
    int dp = nums[0];
    int ret = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      dp = nums[i] + max(dp, 0);
      ret = max(ret, dp);
    }

    return ret;
  }

  int maxSubArray(vector<int>& nums) {
    vector<int> dp = {nums[0]};
    int ret = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      dp.push_back(nums[i] + max(dp[i-1], 0));
      ret = max(ret, dp[i]);
    }

    return ret;
  }
};

int main() {

  Solution sol;
  vector<int> nums;
  int ans;

  nums = {-2,1,-3,4,-1,2,1,-5,4};
  ans = sol.maxSubArray(nums);
  assert(ans == 6);

  nums = {1};
  ans = sol.maxSubArray(nums);
  assert(ans == 1);

  nums = {5,4,-1,7,8};
  ans = sol.maxSubArray(nums);
  assert(ans == 23);

  return 0;

}
