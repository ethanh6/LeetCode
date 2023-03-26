/*
Given an array of strings `strs`, group **the anagrams** together. You can
return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a
different word or phrase, typically using all the original letters exactly
once.

 **Example 1:**



     **Input:** strs = ["eat","tea","tan","ate","nat","bat"] **Output:**
[["bat"],["nat","tan"],["ate","eat","tea"]]

 **Example 2:**



     **Input:** strs = [""] **Output:** [[""]]

 **Example 3:**



     **Input:** strs = ["a"] **Output:** [["a"]]

 **Constraints:**

  * `1 <= strs.length <= 104`
  * `0 <= strs[i].length <= 100`
  * `strs[i]` consists of lowercase English letters.


*/

#include "leetcode.hpp"

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {

    unordered_map<string, vector<string>> _map;
    for (const string &str: strs) {
      string sorted_str = str;
      sort(sorted_str.begin(), sorted_str.end());
      _map[sorted_str].push_back(str);
    }

    vector<vector<string>> ans{};
    for(auto it = _map.cbegin(); it != _map.cend(); ++it) {
      ans.push_back(it->second);
    }

    return ans;
  }
};

TEST_CASE("group-anagrams", "[0049]") {
  Solution sol;
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> ans{{"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}};
  CHECK(sol.groupAnagrams(strs) == ans);
}

TEST_CASE("group-anagrams - 1", "[0049]") {
  Solution sol;
  vector<string> strs = {""};
  vector<vector<string>> ans{{""}};
  CHECK(sol.groupAnagrams(strs) == ans);
}

TEST_CASE("group-anagrams - 2", "[0049]") {
  Solution sol;
  vector<string> strs = {"a"};
  vector<vector<string>> ans{{"a"}};
  CHECK(sol.groupAnagrams(strs) == ans);
}

TEST_CASE("group-anagrams - 3", "[0049]") {
  Solution sol;
  vector<string> strs = {"zb"};
  vector<vector<string>> ans{{"zb"}};
  CHECK(sol.groupAnagrams(strs) == ans);
}
