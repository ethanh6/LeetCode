/*
Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`,
`'['` and `']'`, determine if the input string is valid.

An input string is valid if:

  1. Open brackets must be closed by the same type of brackets.
  2. Open brackets must be closed in the correct order.
  3. Every close bracket has a corresponding open bracket of the same type.

 **Example 1:**



     **Input:** s = "()" **Output:** true

 **Example 2:**



     **Input:** s = "()[]{}" **Output:** true

 **Example 3:**



     **Input:** s = "(]" **Output:** false

 **Constraints:**

  * `1 <= s.length <= 104`
  * `s` consists of parentheses only `'()[]{}'`.


*/

#include "leetcode.hpp"

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (const auto &c : s) {
      if (c == '(')
        st.push(')');
      else if (c == '[')
        st.push(']');
      else if (c == '{')
        st.push('}');
      else if (st.empty() or st.top() != c)
        return false;
      else
        st.pop();
    }
    return st.empty();
  }
};

TEST_CASE("valid-parentheses", "[0020]") {
  Solution sol;
  string s = "()";
  CHECK(sol.isValid(s));
}

TEST_CASE("valid-parentheses - 1", "[0020]") {
  Solution sol;
  string s = "()[]{}";
  CHECK(sol.isValid(s));
}

TEST_CASE("valid-parentheses - 2", "[0020]") {
  Solution sol;
  string s = "])";
  CHECK_FALSE(sol.isValid(s));
}
