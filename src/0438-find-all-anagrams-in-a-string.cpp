/*
Given two strings `s` and `p`, return _an array of all the start indices
of_`p` _' s anagrams in _`s`. You may return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a
different word or phrase, typically using all the original letters exactly
once.

 **Example 1:**



     **Input:** s = "cbaebabacd", p = "abc" **Output:** [0,6] **Explanation:**
The substring with start index = 0 is "cba", which is an anagram of "abc".The
substring with start index = 6 is "bac", which is an anagram of "abc".

 **Example 2:**



     **Input:** s = "abab", p = "ab" **Output:** [0,1,2] **Explanation:** The
substring with start index = 0 is "ab", which is an anagram of "ab".The
substring with start index = 1 is "ba", which is an anagram of "ab".The
substring with start index = 2 is "ab", which is an anagram of "ab".

 **Constraints:**

  * `1 <= s.length, p.length <= 3 * 104`
  * `s` and `p` consist of lowercase English letters.


*/

#include "leetcode.hpp"

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int ns = s.size(), np = p.size();

    vector<int> ans;
    if (ns < np) {
      return ans;
    }

    unordered_map<char, int> require;
    for (const auto &c : p)
      require[c]++;

    unordered_map<char, int> window;

    int l;
    for (int r = 0; r < s.size(); ++r) {
      // add one char on the right
      window[s[r]]++;

      // l is the to-be-removed element on the left
      l = r - np;

      // remove one char on the left
      if (l >= 0) {
        if (window.find(s[l]) != window.cend() && window[s[l]] == 1)
          window.erase(s[l]);
        else
          window[s[l]]--;
      }

      // check if it's valid anagram
      if (window == require) {
        ans.push_back(l + 1);
      }
    }
    return ans;
  }
};

TEST_CASE("find-all-anagrams-in-a-string", "[0438]") {
  Solution sol;
  string s = "cbaebabacd", p = "abc";
  CHECK(sol.findAnagrams(s, p) == vector<int>{0, 6});

  s = "abab", p = "ab";
  CHECK(sol.findAnagrams(s, p) == vector<int>{0, 1, 2});
}
