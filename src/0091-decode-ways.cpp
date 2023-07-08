/*
A message containing letters from `A-Z` can be **encoded** into numbers using
the following mapping:



    'A' -> "1"'B' -> "2"...'Z' -> "26"

To **decode** an encoded message, all the digits must be grouped then mapped
back into letters using the reverse of the mapping above (there may be
multiple ways). For example, `"11106"` can be mapped into:

  * `"AAJF"` with the grouping `(1 1 10 6)`
  * `"KJF"` with the grouping `(11 10 6)`

Note that the grouping `(1 11 06)` is invalid because `"06"` cannot be mapped
into `'F'` since `"6"` is different from `"06"`.

Given a string `s` containing only digits, return _the **number** of ways to
**decode** it_.

The test cases are generated so that the answer fits in a **32-bit** integer.

 **Example 1:**



     **Input:** s = "12" **Output:** 2 **Explanation:** "12" could be decoded as
"AB" (1 2) or "L" (12).

 **Example 2:**



     **Input:** s = "226" **Output:** 3 **Explanation:** "226" could be decoded
as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

 **Example 3:**



     **Input:** s = "06" **Output:** 0 **Explanation:** "06" cannot be mapped to
"F" because of the leading zero ("6" is different from "06").

 **Constraints:**

  * `1 <= s.length <= 100`
  * `s` contains only digits and may contain leading zero(s).


*/

#include "leetcode.hpp"

class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    if (n == 0)
      return 0;

    // definition:
    // dp[i] := numDecodings(s[:i])
    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = s[0] == '0' ? 0 : 1;

    for (size_t i = 2; i < dp.size(); ++i) {
      // single digit decode
      if (s[i - 1] != '0') {
        dp[i] = dp[i - 1];
      }

      // double digit
      int candidate = stoi(s.substr(i - 2, 2));
      if (candidate >= 10 and candidate <= 26) {
        dp[i] += dp[i - 2];
      }
    }

    return dp.back();
  }
};

TEST_CASE("decode-ways", "[0091]") {
  Solution sol;
  string s("12");
  int output = 2;
  CHECK(sol.numDecodings(s) == output);
}

TEST_CASE("decode-ways - 1", "[0091]") {
  Solution sol;
  string s("226");
  int output = 3;
  CHECK(sol.numDecodings(s) == output);
}

TEST_CASE("decode-ways - 2", "[0091]") {
  Solution sol;
  string s("06");
  int output = 0;
  CHECK(sol.numDecodings(s) == output);
}

TEST_CASE("decode-ways - 3", "[0091]") {
  Solution sol;
  string s("27");
  int output = 1;
  CHECK(sol.numDecodings(s) == output);
}
