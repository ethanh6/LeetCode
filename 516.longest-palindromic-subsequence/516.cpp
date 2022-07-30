
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

class Solution {
public:
  int longestPalindromeSubseq(string s) {

    int n = s.size();
    vector<vector<int>> dp (n, vector<int>(n, 0));

    auto print = [&](){
      for (int i = 0; i < n; i++) {
        for (int j= 0; j < n; j++) {
          cout << dp[i][j] << " ";
        }
        cout << endl;
      }
    };

    for (int i = n - 1; i >= 0; i--) {
      for (int j = i; j < n; j++) {
        if (i == j) {
          dp[i][j] = 1;
        } else {
          if (s[i] == s[j]) {
            dp[i][j] = dp[i+1][j-1] + 2;
          } else {
            dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
          }
        }
      }
    }

    print();
    return dp[0][n-1];
  }
};

int main() {

  Solution sol;
  int ans;
  string s;


  s = "bbbab";
  ans = sol.longestPalindromeSubseq(s);
  assert(ans == 4);


  s = "cbbd";
  ans = sol.longestPalindromeSubseq(s);
  assert(ans == 2);

  return 0;
}
