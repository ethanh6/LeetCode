#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp (m + 1, vector<int>(n + 1, 0));

    // print helper function
    // auto print = [&]() {
    //   for (int i = 0 ; i < m + 1 ; i++) {
    //     for (int j = 0 ; j < n + 1 ; j++) {
    //       cout << dp[i][j] << " " ;
    //     }
    //     cout << endl;
    //   }
    // };

    // fill the table
    for (int i = 1 ; i < m + 1 ; i++) {
      for (int j = 1 ; j < n + 1 ; j++) {
        // dp[i][j] = text1[i - 1] == text2[j - 1] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);

        // notice: the index of the table is different that the index of the string
        if (text1[i-1] == text2[j-1]) {
          dp[i][j] = dp[i-1][j-1] + 1;
        } else {
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
      }
    }

    // print();

    return dp[m][n];
  }
};


int main() {

  Solution sol;
  string t1, t2;
  int ans;


  t2 = "abcde";
  t1 = "ace";
  cout << "(s, t) = (" << t1 << ", " << t2 << ")" << endl;
  ans = sol.longestCommonSubsequence(t1, t2);
  assert(ans == 3);

  t1 = "abc";
  t2 = "abc";
  cout << "(s, t) = (" << t1 << ", " << t2 << ")" << endl;
  ans = sol.longestCommonSubsequence(t1, t2);
  assert(ans == 3);

  t1 = "abc";
  t2 = "xxx";
  cout << "(s, t) = (" << t1 << ", " << t2 << ")" << endl;
  ans = sol.longestCommonSubsequence(t1, t2);
  cout << "ans=" << endl;
  assert(ans == 0);

  return 0;
}
