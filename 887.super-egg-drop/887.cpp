
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

class Solution {
public:
  // State: k eggs & n floor
  // Selection: pick a floor to throw egg
  // State Transition: 

  void print() {

  }

  int helper(vector<vector<int>>& dp, int k, int n) {
    // base case
    if (k == 1) return n;
    if (n == 0) return 0;

    for (int i = 1; i < k + 1; i++){
      for (int j = 1; j < n + 1; j++){
        // base cases
        if (i == 1){
          dp[i][j] = j;
        } else if (j == 1) {
          dp[i][j] = 1;
        }

        dp[i][j] = 1 + min(dp[i][n-j], dp[i-1][j-1]);
      }
    }

    return dp[k][n];
  }

  int superEggDrop(int k, int n) {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    return helper(dp, k, n);
  }
};

int main() {

  Solution sol;
  int ans;
  int k, n;

  k = 1;
  n = 2;
  ans = sol.superEggDrop(k, n);
  assert(ans == 2);

  k = 2;
  n = 6;
  ans = sol.superEggDrop(k, n);
  cout << ans << endl;
  assert(ans == 3);

  return 0;
}
