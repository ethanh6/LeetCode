/*
Given two strings `s` and `t`, return `true` _if_ `t` _is an anagram of_ `s`
_, and_ `false` _otherwise_.

An **Anagram** is a word or phrase formed by rearranging the letters of a
different word or phrase, typically using all the original letters exactly
once.

 **Example 1:**

    
    
     **Input:** s = "anagram", t = "nagaram" **Output:** true

 **Example 2:**

    
    
     **Input:** s = "rat", t = "car" **Output:** false

 **Constraints:**

  * `1 <= s.length, t.length <= 5 * 104`
  * `s` and `t` consist of lowercase English letters.

 **Follow up:** What if the inputs contain Unicode characters? How would you
adapt your solution to such a case?


*/

#include "leetcode.hpp"

class Solution {
public:
    bool isAnagram(string s, string t) {
      if (s.size() != t.size()) {
        return false;
      }
      vector<int> ss(26), tt(26);
      for (int i = 0; i < s.size(); ++i) {
        ss[s[i] - 97]++;
        tt[t[i] - 97]++;
      }
      return ss == tt;
    }
};

TEST_CASE("valid-anagram", "[0242]"){
    Solution s;
    REQUIRE(s.isAnagram(string("anagram"), string("nagaram")));
    REQUIRE_FALSE(s.isAnagram(string("rat"), string("car")));
}
