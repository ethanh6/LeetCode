
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:

  // generic 2 sum with target
  vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    int lo = start;
    int hi = nums.size() - 1;
    int left, right, sum;

    while (lo < hi) {

      left = nums[lo];
      right = nums[hi];

      sum = left + right;
      
      // move both lo and hi ptr 
      // to make sure there are no duplicates
      if (sum < target) {
        while (lo < hi && nums[lo] == left) { lo++; }
      } else if (sum > target) {
        while (lo < hi & nums[hi] == right) { hi--; }
      } else {
        ret.push_back({left, right});
        while (lo < hi && nums[lo] == left) { lo++; }
        while (lo < hi && nums[hi] == right) { hi--; }
      }

    }

    return ret;
  }

  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;

    for (int i = 0; i < nums.size(); i++) {
      // perform 2 sum with target = 0 - nums[i]
      vector<vector<int>> ts = twoSum(nums, i + 1, - nums[i]);

      // each triplet is a solution
      for(auto t: ts) {
        // triplet = {nums[i], t[0], t[1]};
        ret.push_back(vector<int>{nums[i], t[0], t[1]});
      }

      // update i to avoid duplicate nums[i]
      while (i < nums.size() && nums[i] == nums[i+1]) {
        i++;
      }
    }

    return ret;
  }
};

int main() {

  Solution sol;
  vector<vector<int>> ans, ret;
  vector<int> nums;

  ans = {{-1,-1,2}, {-1,0,1}};
  nums = {-1,0,1,2,-1,-4};
  ret = sol.threeSum(nums);
  assert(ans == ret);
  cout << "(1) all tests passed" << endl;

  ans = {};
  nums = {0, 1, 1};
  ret = sol.threeSum(nums);
  assert(ans == ret);
  cout << "(2) all tests passed" << endl;

  ans = {{0, 0, 0}};
  nums = {0, 0, 0, 0};
  ret = sol.threeSum(nums);
  assert(ans == ret);
  cout << "(3) all tests passed" << endl;
    


  return 0;
}
