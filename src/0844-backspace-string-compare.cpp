/*
Given two strings `s` and `t`, return `true` _if they are equal when both are
typed into empty text editors_. `'#'` means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 **Example 1:**



     **Input:** s = "ab#c", t = "ad#c" **Output:** true **Explanation:** Both s
and t become "ac".

 **Example 2:**



     **Input:** s = "ab##", t = "c#d#" **Output:** true **Explanation:** Both s
and t become "".

 **Example 3:**



     **Input:** s = "a#c", t = "b" **Output:** false **Explanation:** s becomes
"c" while t becomes "b".

 **Constraints:**

  * `1 <= s.length, t.length <= 200`
  * `s` and `t` only contain lowercase letters and `'#'` characters.

 **Follow up:** Can you solve it in `O(n)` time and `O(1)` space?


*/

#include "leetcode.hpp"

class Solution0 {
public:
  bool backspaceCompare(string s, string t) {
    stack<char> st1, st2;

    for (const auto &c : s) {
      if (c == '#') {
        if (st1.size())
          st1.pop();
      } else {
        st1.push(c);
      }
    }

    for (const auto &c : t) {
      if (c == '#') {
        if (st2.size())
          st2.pop();
      } else {
        st2.push(c);
      }
    }

    return st1 == st2;
  }
};

class Solution {
public:
  bool backspaceCompare(string s, string t) {
    int i = s.size() - 1, j = t.size() - 1;
    int skipS = 0, skipT = 0;
    while (i >= 0 || j >= 0) {
      // find next possible char of s and t
      while (i >= 0) {
        if (s[i] == '#') {
          ++skipS;
          --i;
        } else if (skipS > 0) {
          --skipS;
          --i;
        } else {
          break;
        }
      }
      while (j >= 0) {
        if (t[j] == '#') {
          ++skipT;
          --j;
        } else if (skipT > 0) {
          --skipT;
          --j;
        } else {
          break;
        }
      }

      // char doesn't match
      if (i >= 0 && j >= 0 && s[i] != t[j])
        return false;

      // compare char and nothing
      if ((i >= 0) != (j >= 0))
        return false;

      --i;
      --j;
    }

    return true;
  }
};

TEST_CASE("backspace-string-compare", "[0844]") {
  Solution sol;
  string s = "ab#c", t = "ad#c";
  CHECK(sol.backspaceCompare(s, t));
}

TEST_CASE("backspace-string-compare - 1", "[0844]") {
  Solution sol;
  string s = "ab##", t = "c#d#";
  CHECK(sol.backspaceCompare(s, t));
}

TEST_CASE("backspace-string-compare - 2", "[0844]") {
  Solution sol;
  string s = "a#c", t = "b";
  CHECK_FALSE(sol.backspaceCompare(s, t));
}
