/*
You are given a **0-indexed** array of **unique** strings `words`.

A **palindrome pair** is a pair of integers `(i, j)` such that:

  * `0 <= i, j < words.length`,
  * `i != j`, and
  * `words[i] + words[j]` (the concatenation of the two strings) is a
palindrome.

Return _an array of all the **palindrome pairs** of _`words`.

 **Example 1:**



     **Input:** words = ["abcd","dcba","lls","s","sssll"] **Output:**
[[0,1],[1,0],[3,2],[2,4]] **Explanation:** The palindromes are
["abcddcba","dcbaabcd","slls","llssssll"]

 **Example 2:**



     **Input:** words = ["bat","tab","cat"] **Output:** [[0,1],[1,0]]
**Explanation:** The palindromes are ["battab","tabbat"]

 **Example 3:**



     **Input:** words = ["a",""] **Output:** [[0,1],[1,0]] **Explanation:** The
palindromes are ["a","a"]

 **Constraints:**

  * `1 <= words.length <= 5000`
  * `0 <= words[i].length <= 300`
  * `words[i]` consists of lowercase English letters.


*/

#include "leetcode.hpp"

class Solution_0 {
public:
  bool isPalindrome(const string &s) {
    if (s.size() == 0)
      return true;
    int i = 0, j = s.size() - 1;
    while (i <= j) {
      if (s[i++] != s[j--]) {
        return false;
      }
    }
    return true;
  }

  string rev(string s) {
    std::reverse(s.begin(), s.end());
    return s;
  }

  vector<string> valid_prefixes(const string &s) {
    vector<string> result;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      // if the suffix is palindrome,
      // the prefix can be used to match
      if (isPalindrome(s.substr(i, n - i))) {
        result.push_back(s.substr(0, i));
      }
    }
    return result;
  }

  vector<string> valid_suffixes(const string &s) {
    vector<string> result;
    int n = s.size();
    for (int i = 1; i <= n; ++i) {
      // if the prefix is palindrome
      // the suffix can be used to match
      if (isPalindrome(s.substr(0, i))) {
        result.push_back(s.substr(i, n - i));
      }
    }
    return result;
  }

  // main function
  vector<vector<int>> palindromePairs(vector<string> &words) {
    int n = words.size();

    unordered_map<string, int> lookup;
    for (int i = 0; i < n; ++i)
      lookup[words[i]] = i;

    vector<vector<int>> result{};

    for (int i = 0; i < n; ++i) {
      string w = words[i];
      string reversed_w = rev(w);

      // case 1
      if (lookup.count(reversed_w) != 0 && lookup[reversed_w] != i) {
        result.push_back(vector<int>{i, lookup[reversed_w]});
      }

      // case 2
      vector<string> prefixes = valid_prefixes(w);
      for (const auto &pref : prefixes) {
        string rev_pref = rev(pref);
        if (lookup.count(rev_pref) != 0) {
          result.push_back(vector<int>{i, lookup[rev_pref]});
        }
      }

      // case 3
      vector<string> suffixes = valid_suffixes(w);
      for (const auto &suff : suffixes) {
        string rev_suff = rev(suff);
        if (lookup.count(rev_suff) != 0) {
          result.push_back(vector<int>{lookup[rev_suff], i});
        }
      }
    }

    return result;
  }
};

// for Solution_0
TEST_CASE("isPalindrome") {
  string s("abc");
  REQUIRE_FALSE(Solution_0().isPalindrome(s));
  s = "aaa";
  REQUIRE(Solution_0().isPalindrome(s));
  s = "";
  REQUIRE(Solution_0().isPalindrome(s));
}

TEST_CASE("reverse") {
  Solution_0 s;
  CHECK(s.rev("abc") == "cba");
  CHECK(s.rev("") == "");
}

TEST_CASE("prefix") {
  string s("abbb");
  CHECK(Solution_0().valid_prefixes(s) == vector<string>{"a", "ab", "abb"});
  s = "";
  CHECK(Solution_0().valid_prefixes(s) == vector<string>{});
  s = "abccb";
  CHECK(Solution_0().valid_prefixes(s) == vector<string>{"a", "abcc"});
}

TEST_CASE("suffix") {
  string s("abc");
  CHECK(Solution_0().valid_suffixes(s) == vector<string>{"bc"});
  s = "";
  CHECK(Solution_0().valid_suffixes(s) == vector<string>{});
  s = "bbba";
  CHECK(Solution_0().valid_suffixes(s) == vector<string>{"bba", "ba", "a"});
}

TEST_CASE("palindrome-pairs", "[0336]") {
  Solution_0 sol;
  vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
  vector<vector<int>> output = {{0, 1}, {1, 0}, {3, 2}, {2, 4}};
  CHECK(sol.palindromePairs(words) == output);
}

TEST_CASE("palindrome-pairs - 1", "[0336]") {
  Solution_0 sol;
  vector<string> words = {"bat", "tab", "cat"};
  vector<vector<int>> output = {{0, 1}, {1, 0}};
  CHECK(sol.palindromePairs(words) == output);
}

// class Solution_1 {
// public:
//   // main function
//   vector<vector<int>> palindromePairs(vector<string> &words) {}
// };
//
//
// // for Solution_1
// {
//   TEST_CASE("palindrome-pairs", "[0336]") {
//     Solution_1 sol;
//     vector<string> words = {"bat", "tab", "cat"};
//     vector<vector<int>> output = {{0, 1}, {1, 0}};
//     CHECK(sol.palindromePairs(words) == output);
//   }
//
// }
