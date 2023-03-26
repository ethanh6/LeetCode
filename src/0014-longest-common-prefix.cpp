/*
Write a function to find the longest common prefix string amongst an array of
strings.

If there is no common prefix, return an empty string `""`.

 **Example 1:**



     **Input:** strs = ["flower","flow","flight"] **Output:** "fl"

 **Example 2:**



     **Input:** strs = ["dog","racecar","car"] **Output:** "" **Explanation:**
There is no common prefix among the input strings.

 **Constraints:**

  * `1 <= strs.length <= 200`
  * `0 <= strs[i].length <= 200`
  * `strs[i]` consists of only lowercase English letters.


*/

#include "leetcode.hpp"

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    // sort based on length
    sort(strs.begin(), strs.end(),
         [&](const string &a, const string &b) { return a.size() < b.size(); });

    // min_str is the string with minimum length
    string min_str = strs[0];
    int min_len = min_str.size();
    pair<int, string> ans(INT_MAX, string(""));

    // when iterating thru every string,
    // only search up to min_len
    for (const auto &str : strs) {
      int r = 0;
      for (; r < min_len; ++r) 
        if (str[r] != min_str[r])
          break;

      // update answer
      if (r < ans.first) 
        ans = pair<int, string>(r, min_str.substr(0, r));
    }

    return ans.second;
  }
};

TEST_CASE("longest-common-prefix", "[0014]") {
  Solution sol;
  vector<string> strs{"flower", "flow", "flight"};
  string ans("fl");
  CHECK(sol.longestCommonPrefix(strs) == ans);
}

TEST_CASE("longest-common-prefix - 1", "[0014]") {
  Solution sol;
  vector<string> strs{"dog", "racecar", "car"};
  string ans("");
  CHECK(sol.longestCommonPrefix(strs) == ans);
}
