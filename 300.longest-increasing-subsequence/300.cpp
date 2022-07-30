#include <iostream>
#include <unordered_map>
#include <vector>
#include "assert.h"

using namespace std;

class Solution {
public:
  int lengthOfLIS_BinarySearch(vector<int>& nums) {
    vector<int> sub = {nums[0]};

    // perform binary search on sub
    // to find the insertion point of num
    int left, right, mid;
    int n;

    for (int i = 1; i < nums.size(); i++) {
      // current num
      n = nums[i];

      // setup ptrs for binary search
      left = 0;
      right = sub.size() - 1;

      // binary search
      while (left <= right) {
        mid = left + (right - left) / 2; // floor division
        if (n > sub[mid]) {
          left = mid + 1;
        }
        else if (n < sub[mid]) {
          right = mid - 1;
        }
        else if (n == sub[mid]) {
          right = mid - 1;
        }
      }

      // escape condition: left > right
      // so left can be out of bounds.
      if (left == sub.size()) {
        // if left if out of bounds, append it 
        // at the end of sub
        sub.insert(sub.end(), n);
      }
      else {
        // replace the value at index left
        // with value n
        sub[left] = n;
      }

      for (auto x: sub) {cout << x << " " ;} cout << endl;
    }
    return sub.size();
  }
  int lengthOfLIS(vector<int>& nums) {
    // initialize dp to all 1's
    // as same size of nums
    vector<int> dp(nums.size(), 1);
    int ret = 0;
    
    // fill in the array
    for (int i = 0; i < nums.size(); ++i){

      // compare nums[i] with all nums[j]
      // update if the number if valid to form LIC
      // and find the best LIC solution
      for (int j = 0; j < i; ++j){
        if (nums[i] > nums[j]) {
          dp[i] = std::max(dp[j] + 1, dp[i]);
        }
      }
      
      // update return value on-the-fly
      ret = std::max(ret, dp[i]);
    }

    return ret;
  }
    
};

int main() {
  Solution sol;
  vector<int> nums;
  int ans;

  // test case 1
  nums = {10,9,2,5,3,7,101,18};
  ans = sol.lengthOfLIS(nums);
  assert(ans == 4);
  ans = sol.lengthOfLIS_BinarySearch(nums);
    cout << ans << endl;
  assert(ans == 4);


  // test case 2
  nums = {0,1,0,3,2,3};
  ans = sol.lengthOfLIS(nums);
  assert(ans == 4);
  ans = sol.lengthOfLIS_BinarySearch(nums);
  assert(ans == 4);


  // test case 3
  nums = {7,7,7,7,7,7,7};
  ans = sol.lengthOfLIS(nums);
  assert(ans == 1);
  ans = sol.lengthOfLIS_BinarySearch(nums);
  assert(ans == 1);


  // test case 4
  nums = {6,3,5,10,11,2,9,14,13,7,4,8,12};
  ans = sol.lengthOfLIS(nums);
  assert(ans == 5);
  ans = sol.lengthOfLIS_BinarySearch(nums);
  assert(ans == 5);

  cout << "all test passed" << endl;
  return 0;

}
