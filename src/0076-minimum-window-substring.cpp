/*
Given two strings `s` and `t` of lengths `m` and `n` respectively, return _the
**minimum window**_ **_substring_** _of_`s` _such that every character in_`t`
_( **including duplicates** ) is included in the window_. If there is no such
substring, return _the empty string_`""`.

The testcases will be generated such that the answer is **unique**.

 **Example 1:**



     **Input:** s = "ADOBECODEBANC", t = "ABC" **Output:** "BANC"
**Explanation:** The minimum window substring "BANC" includes 'A', 'B', and 'C'
from string t.

 **Example 2:**



     **Input:** s = "a", t = "a" **Output:** "a" **Explanation:** The entire
string s is the minimum window.

 **Example 3:**



     **Input:** s = "a", t = "aa" **Output:** "" **Explanation:** Both 'a's from
t must be included in the window.Since the largest window of s only has one 'a',
return empty string.

 **Constraints:**

  * `m == s.length`
  * `n == t.length`
  * `1 <= m, n <= 105`
  * `s` and `t` consist of uppercase and lowercase English letters.

 **Follow up:** Could you find an algorithm that runs in `O(m + n)` time?


*/

#include "leetcode.hpp"

class Solution {
public:
  string minWindow(string s, string t) {
    if (s.size() < t.size()) {
      return "";
    }

    // non-updating vars
    unordered_map<char, int> required;
    for (const char &c : t) {
      required[c] += 1;
    }

    // updating vars
    unordered_map<char, int> window;
    int formed = 0;
    int result_len = INT_MAX;
    string result_str = string("");

    char c, d;

    for (int l = 0, r = 0; r < s.size(); ++r) {
      c = s[r];

      // expand window
      if (required.count(c)) {

        window[c] += 1;

        // update formed
        if (window[c] == required[c]) {
          formed++;
        }
      }

      // found a solution
      // update result and shrink window
      while (formed == required.size() && l <= r) {

        // update reuslt
        if (r - l + 1 < result_len) {
          result_len = r - l + 1;
          result_str = s.substr(l, result_len);
        }

        d = s[l];
        l++;

        // shrink window : update window & update formed
        if (required.count(d)) {
          if (window[d] == required[d])
            formed--;
          window[d]--;
        }
      }
    }
    return result_str;
  }
};

TEST_CASE("minimum-window-substring", "[0076]") {
  Solution sol;
  string s("ADOBECODEBANC"), t = ("ABC");
  REQUIRE(sol.minWindow(s, t) == "BANC");
}

TEST_CASE("minimum-window-substring - 1", "[0076]") {
  Solution sol;
  string s("a"), t = ("a");
  REQUIRE(sol.minWindow(s, t) == "a");
}

TEST_CASE("minimum-window-substring - 2", "[0076]") {
  Solution sol;
  string s("a"), t = ("aa");
  REQUIRE(sol.minWindow(s, t) == "");
}

TEST_CASE("minimum-window-substring - 3", "[0076]") {
  Solution sol;
  string s("cabwefgewcwaefgcf"), t = ("cae");
  REQUIRE(sol.minWindow(s, t) == "cwae");
}
