/*
**Example 1:**



     **Input:** s = "abccccdd" **Output:** 7 **Explanation:** One longest
palindrome that can be built is "dccaccd", whose length is 7.

 **Example 2:**



     **Input:** s = "a" **Output:** 1 **Explanation:** The longest palindrome
that can be built is "a", whose length is 1.

 **Constraints:**

  * `1 <= s.length <= 2000`


*/

#include "leetcode.hpp"

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> m;
    for (const auto &c : s) {
      m[c] += 1;
    }

    int odd = 0;

    for (const auto &[k, v] : m) {
      odd += v & 1;
    }

    return s.size() - odd + (odd > 0);
  }
};

TEST_CASE("longest-palindrome", "[0409]") {
  Solution s;
  REQUIRE(s.longestPalindrome(string("abccccdd")) == 7);
}

TEST_CASE("longest-palindrome - 1", "[0409]") {
  Solution s;
  REQUIRE(s.longestPalindrome("a") == 1);
}

TEST_CASE("longest-palindrome - 2", "[0409]") {
  Solution s;
  REQUIRE(s.longestPalindrome(string("bb")) == 2);
}
