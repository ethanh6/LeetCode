#include <iostream>
#include <vector>
// #include "algorithm"
#include "assert.h"

using namespace std;

class Solution {
public:
  int maxEnvelopes_BinarySearch(vector<vector<int>>& envelopes) {

    // sort with lambda expression as cmp obj
    // as ascending order 
    // (smaller items has higher priority)
    // NOTE: the inplace sort can be done since envelopes is passed by reference
    std::sort(envelopes.begin(), envelopes.end(), [&](vector<int>& a, vector<int>& b){return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];});


    vector<int> sub = {envelopes[0][1]};
    int left, right, mid, target;

    // try to insert each elem (target) of env into sub
    for (int i = 1; i < envelopes.size(); i++){
      target = envelopes[i][1];

      // ptrs for binary search
      left = 0;
      right = sub.size() - 1;

      // exit condition: left == right + 1
      // find the appropriate index left to insert
      while (left <= right) {
        mid = left + (right - left) / 2; // prevent overflow
        // if (target > sub[mid]) {
        //   left = mid + 1;
        // } else if (target < sub[mid]) {
        //   right = mid - 1;
        // } else if (target == sub[mid]) {
        //   right = mid - 1;
        // }
        if (target > sub[mid]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }

      // insert left into sub
      if (left == sub.size()) {
        sub.insert(sub.end(), target);
      } else {
        sub[left] = target;
      }
    }
    return sub.size();
  }

  int maxEnvelopes(vector<vector<int>>& envelopes) {
    // make a local copy for sort algorithm
    vector<vector<int>> envs = envelopes;

    // sort with lambda expression as cmp obj
    // as ascending order 
    // (smaller items has higher priority)
    std::sort(envs.begin(), envs.end(),
              [&](vector<int>& a, vector<int>& b){return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];});


    // the 2d vector has been sorted by first elem
    // so perform LIC algo on the second elem
    // subproblem (LIC): 300 longest increasing subsequence

    // init dp value to all ones
    vector<int> dp(envs.size(), 1);
    int ret = 0;

    // fill in the dp table
    for (int i = 0; i < dp.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (envs[i][1] > envs[j][1]) {
          dp[i] = std::max(dp[i], dp[j] + 1);
        }
      }
      ret = std::max(ret, dp[i]);
    }

    return ret;
  }
};

int main() {

  Solution sol;
  vector<vector<int>> envs;
  int ans;

  // test case 1
  envs = {{5,4},{6,4},{6,7},{2,3}};
  ans = sol.maxEnvelopes(envs);
  assert(ans == 3);
  ans = sol.maxEnvelopes_BinarySearch(envs);
  assert(ans == 3);

  // test case 2
  envs = { {1,1}, {1,1}, {1,1}, {1,1},};
  ans = sol.maxEnvelopes(envs);
  assert(ans == 1);
  ans = sol.maxEnvelopes_BinarySearch(envs);
  assert(ans == 1);

  // test case 3
  envs = {{4,5},{4,6},{6,7},{2,3},{1,1}};
  ans = sol.maxEnvelopes(envs);
  assert(ans == 4);
  ans = sol.maxEnvelopes_BinarySearch(envs);
  assert(ans == 4);

  // test case 4
  envs = {{1,8},{2,3},{5,4},{5,2},{6,7},{6,4}};
  ans = sol.maxEnvelopes(envs);
  assert(ans == 3);
  ans = sol.maxEnvelopes_BinarySearch(envs);
  assert(ans == 3);

  cout << "all test passed" << endl;
  return 0;
}
