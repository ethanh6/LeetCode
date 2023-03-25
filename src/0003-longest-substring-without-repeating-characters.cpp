/*
Given a string `s`, find the length of the **longest** **substring** without
repeating characters.

 **Example 1:**



     **Input:** s = "abcabcbb" **Output:** 3 **Explanation:** The answer is
"abc", with the length of 3.

 **Example 2:**



     **Input:** s = "bbbbb" **Output:** 1 **Explanation:** The answer is "b",
with the length of 1.

 **Example 3:**



     **Input:** s = "pwwkew" **Output:** 3 **Explanation:** The answer is "wke",
with the length of 3.Notice that the answer must be a substring, "pwke" is a
subsequence and not a substring.

 **Constraints:**

  * `0 <= s.length <= 5 * 104`
  * `s` consists of English letters, digits, symbols and spaces.


*/

#include "leetcode.hpp"

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() <= 1) {
      return s.size();
    }

    int ans = INT_MIN;
    unordered_map<char, int> seen;

    for (int l = 0, r = 0; r < s.size(); ++r) {
      char c = s[r];

      if (seen.find(c) != seen.end() && seen[c] >= l) {
        // c is seen and last seen is in the seen
        l = seen[c] + 1;
      } else {
        // c is new, add to window and update ans
        seen[c] = r;
        ans = max(ans, r - l + 1);
      }
      seen[c] = r;
    }

    return ans;
  }
};

TEST_CASE("longest-substring-without-repeating-characters", "[0003]") {
  Solution s;
  string input("abcabcbb");
  REQUIRE(s.lengthOfLongestSubstring(input) == 3);
}

TEST_CASE("longest-substring-without-repeating-characters - 1", "[0003]") {
  Solution s;
  string input("bbbb");
  REQUIRE(s.lengthOfLongestSubstring(input) == 1);
}

TEST_CASE("longest-substring-without-repeating-characters - 2", "[0003]") {
  Solution s;
  string input("pwwkew");
  REQUIRE(s.lengthOfLongestSubstring(input) == 3);
}
