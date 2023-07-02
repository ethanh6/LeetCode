/*
Given a string `s` and a dictionary of strings `wordDict`, return `true` if
`s` can be segmented into a space-separated sequence of one or more dictionary
words.

 **Note** that the same word in the dictionary may be reused multiple times in
the segmentation.

 **Example 1:**



     **Input:** s = "leetcode", wordDict = ["leet","code"] **Output:** true
**Explanation:** Return true because "leetcode" can be segmented as "leet code".

 **Example 2:**



     **Input:** s = "applepenapple", wordDict = ["apple","pen"] **Output:** true
**Explanation:** Return true because "applepenapple" can be segmented as "apple
pen apple".Note that you are allowed to reuse a dictionary word.

 **Example 3:**



     **Input:** s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
**Output:** false

 **Constraints:**

  * `1 <= s.length <= 300`
  * `1 <= wordDict.length <= 1000`
  * `1 <= wordDict[i].length <= 20`
  * `s` and `wordDict[i]` consist of only lowercase English letters.
  * All the strings of `wordDict` are **unique**.


*/

#include "leetcode.hpp"

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    vector<bool> dp{true};
    set<string> wordSet(wordDict.begin(), wordDict.end());

    // Note: how to iterate through possible substrings
    // s.substr(l, r - l) is identical to
    // s[l:r] in python. So, r is non-inclusive.
    for (int r = 1; r < s.size() + 1; ++r) {
      int candidate_count = 0;
      for (int l = 0; l < r; ++l) {
        // increment when both conditions are true
        // 1. previous words are valid
        // 2. cur_word is in wordDict
        string cur_word = s.substr(l, r - l);
        if (dp[l] && wordSet.find(cur_word) != wordSet.end())
          candidate_count++;
      }
      dp.push_back(bool(candidate_count));
    }
    return dp.back();
  }
};

TEST_CASE("word-break", "[0139]") {
  Solution sol;
  string s = "leetcode";
  vector<string> wordDict{"leet", "code"};
  CHECK(sol.wordBreak(s, wordDict));
}

TEST_CASE("word-break - 1", "[0139]") {
  Solution sol;
  string s = "applepenapple";
  vector<string> wordDict{"apple", "pen"};
  CHECK(sol.wordBreak(s, wordDict));
}

TEST_CASE("word-break - 2", "[0139]") {
  Solution sol;
  string s = "catsandog";
  vector<string> wordDict{"cats", "dog", "sand", "and", "cat"};
  CHECK_FALSE(sol.wordBreak(s, wordDict));
}
