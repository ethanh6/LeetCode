
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;


auto mymin = [](int a, int b, int c) {
  return min(min(a, b), c);
};

class Solution {
public:
  int minInsertions(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--){
      for (int j = 0; j < n; j++) {
        if (i >= j) {
          ;
        } else {
          if (s[i] == s[j]) {
            dp[i][j] = dp[i+1][j-1];
          } else {
            dp[i][j] = min(dp[i+1][j] + 1, dp[i][j-1] + 1);
          }
        }
      }
    }

    return dp[0][n - 1];
  }
};

int main() {

  Solution sol;
  int ans;
  string s;

  s = "zzazz";
  ans = sol.minInsertions(s);
  cout << ans << endl;
  assert(ans == 0);

  s = "mbadm";
  ans = sol.minInsertions(s);
  cout << ans << endl;
  assert(ans == 2);

  s = "leetcode";
  ans = sol.minInsertions(s);
  cout << ans << endl;
  assert(ans == 5);


  return 0;
}
