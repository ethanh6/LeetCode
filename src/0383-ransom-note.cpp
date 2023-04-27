/*
Given two strings `ransomNote` and `magazine`, return `true` _if_`ransomNote`
_can be constructed by using the letters from_`magazine` _and_`false`
_otherwise_.

Each letter in `magazine` can only be used once in `ransomNote`.

 **Example 1:**



     **Input:** ransomNote = "a", magazine = "b" **Output:** false

 **Example 2:**



     **Input:** ransomNote = "aa", magazine = "ab" **Output:** false

 **Example 3:**



     **Input:** ransomNote = "aa", magazine = "aab" **Output:** true

 **Constraints:**

  * `1 <= ransomNote.length, magazine.length <= 105`
  * `ransomNote` and `magazine` consist of lowercase English letters.


*/

#include "leetcode.hpp"

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> mp;
    for (const char &c: magazine) 
      mp[c]++;

    for (const char &c: ransomNote)  {
      if (mp.find(c) == mp.end() or mp[c] < 1) {
        return false;
      }
      mp[c]--;
    }
    return true;
  }
};

TEST_CASE("ransom-note", "[0383]") {
  Solution sol;
  string ransomNote = "a", magazine = "b";
  CHECK_FALSE(sol.canConstruct(ransomNote, magazine));
}

TEST_CASE("ransom-note - 1", "[0383]") {
  Solution sol;
  string ransomNote = "aa", magazine = "ab";
  CHECK_FALSE(sol.canConstruct(ransomNote, magazine));
}

TEST_CASE("ransom-note - 2", "[0383]") {
  Solution sol;
  string ransomNote = "aa", magazine = "aab";
  CHECK(sol.canConstruct(ransomNote, magazine));
}
