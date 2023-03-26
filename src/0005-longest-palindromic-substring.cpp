/*
Given a string `s`, return _the longest_ _palindromic_ _substring_ in `s`.

 **Example 1:**



     **Input:** s = "babad" **Output:** "bab" **Explanation:** "aba" is also a
valid answer.

 **Example 2:**



     **Input:** s = "cbbd" **Output:** "bb"

 **Constraints:**

  * `1 <= s.length <= 1000`
  * `s` consist of only digits and English letters.


*/

#include "leetcode.hpp"

class Solution {
public:
  auto expand(string &s, int l, int r) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      l--;
      r++;
    }
    l++; // l is starting position
    return pair<int, string>(r - l, s.substr(l, r - l));
  }
  string longestPalindrome(string s) {
    pair<int, string> result(INT_MIN, string(""));
    for (int i = 0; i < s.size(); ++i) {
      auto odd = expand(s, i, i);
      auto even = expand(s, i, i + 1);
      if (odd.first > result.first) {
        result = odd;
      }
      if (even.first > result.first) {
        result = even;
      }
    }
    return result.second;
  }
};

class Solution_1 {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    string res("");
    int len = INT_MIN;
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // fill the table
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        if (i == j) {
          dp[i][j] = true;
        } else if (s[i] == s[j]) {
          if (j - i == 1) {
            dp[i][j] = true;
          } else {
            dp[i][j] = dp[i + 1][j - 1];
          }
        }

        // update answer
        if (dp[i][j] && (j - i + 1 > len)) {
          res = s.substr(i, j - i + 1);
          len = j - i + 1;
        }
      }
    }
    return res;
  }
};

TEST_CASE("longest-palindromic-substring", "[0005]") {
  Solution sol;
  auto ans = sol.longestPalindrome("babad");
  bool judge = ans == "aba" || ans == "bab";
  REQUIRE(judge);
}

TEST_CASE("longest-palindromic-substring - 1", "[0005]") {
  Solution_1 sol;
  auto ans = sol.longestPalindrome("babad");
  bool judge = ans == "aba" || ans == "bab";
  REQUIRE(judge);
}
