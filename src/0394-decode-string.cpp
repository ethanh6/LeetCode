/*
Given an encoded string, return its decoded string.

The encoding rule is: `k[encoded_string]`, where the `encoded_string` inside
the square brackets is being repeated exactly `k` times. Note that `k` is
guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white
spaces, square brackets are well-formed, etc. Furthermore, you may assume that
the original data does not contain any digits and that digits are only for
those repeat numbers, `k`. For example, there will not be input like `3a` or
`2[4]`.

The test cases are generated so that the length of the output will never
exceed `105`.

 **Example 1:**



     **Input:** s = "3[a]2[bc]" **Output:** "aaabcbc"

 **Example 2:**



     **Input:** s = "3[a2[c]]" **Output:** "accaccacc"

 **Example 3:**



     **Input:** s = "2[abc]3[cd]ef" **Output:** "abcabccdcdcdef"

 **Constraints:**

  * `1 <= s.length <= 30`
  * `s` consists of lowercase English letters, digits, and square brackets
`'[]'`.
  * `s` is guaranteed to be **a valid** input.
  * All the integers in `s` are in the range `[1, 300]`.


*/

#include "leetcode.hpp"

class Solution {
public:
  string decodeString(string s) {
    stack<char> st;

    for (const auto &c : s) {
      if (c != ']') {
        st.push(c);
        continue;
      }

      string decodedStr = "";

      // get encoded string
      for (; st.top() != '['; st.pop())
        decodedStr += st.top();

      // pop [
      st.pop();

      // get repetition number k
      int k = 0;
      for (int base = 1; !st.empty() && isdigit(st.top()); st.pop()) {
        k += (st.top() - '0') * base;
        base *= 10;
      }

      // push decodedStr to stack, k times
      int sizeOfDecodedStr = decodedStr.size();
      while (k--)
        for (int i = sizeOfDecodedStr - 1; i >= 0; --i)
          st.push(decodedStr[i]);
    }

    // build answer from stack
    string answer = "";
    for (; !st.empty(); st.pop()) {
      answer.insert(answer.begin(), st.top());
    }

    return answer;
  }
};

TEST_CASE("decode-string", "[0394]") {
  Solution sol;
  string s = "3[a]2[bc]", output = "aaabcbc";
  CHECK(sol.decodeString(s) == output);
}

TEST_CASE("decode-string - 1", "[0394]") {
  Solution sol;
  string s = "3[a2[c]]", output = "accaccacc";
  CHECK(sol.decodeString(s) == output);
}

TEST_CASE("decode-string - 2", "[0394]") {
  Solution sol;
  string s = "2[abc]3[cd]ef", output = "abcabccdcdcdef";
  CHECK(sol.decodeString(s) == output);
}

TEST_CASE("decode-string - 3", "[0394]") {
  Solution sol;
  string s = "ab3[a2[2[3[j]l]xy]]", output = "abajjjljjjlxyjjjljjjlxyajjjljjjlxyjjjljjjlxyajjjljjjlxyjjjljjjlxy";
  CHECK(sol.decodeString(s) == output);
}

