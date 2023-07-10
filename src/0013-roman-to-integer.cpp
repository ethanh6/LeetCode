/*

    **Symbol**       **Value** I             1V             5X             10L
50C             100D             500M             1000

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not `IIII`. Instead, the number four is
written as `IV`. Because the one is before the five we subtract it making
four. The same principle applies to the number nine, which is written as `IX`.
There are six instances where subtraction is used:

  * `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

 **Example 1:**



     **Input:** s = "III" **Output:** 3 **Explanation:** III = 3.

 **Example 2:**



     **Input:** s = "LVIII" **Output:** 58 **Explanation:** L = 50, V= 5, III
= 3.

 **Example 3:**



     **Input:** s = "MCMXCIV" **Output:** 1994 **Explanation:** M = 1000, CM =
900, XC = 90 and IV = 4.

 **Constraints:**

  * `1 <= s.length <= 15`


*/

#include "leetcode.hpp"

class Solution0 {
public:
  int romanToInt(string s) {
    unordered_map<char, int> map{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                 {'C', 100}, {'D', 500}, {'M', 1000}};

    int n = s.size(), res = 0;

    for (size_t i{}; i < n - 1; ++i) {
      res += map[s[i]] < map[s[i + 1]] ? -map[s[i]] : map[s[i]];
    }
    res += map[s.back()];

    return res;
  }
};

class Solution {
public:
  int romanToInt(string s) {
    unordered_map<string, int> map{
        {"I", 1},   {"V", 5},    {"X", 10},  {"L", 50}, {"C", 100},
        {"D", 500}, {"M", 1000}, {"IV", 4},  {"IX", 9}, {"XL", 40},
        {"XC", 90}, {"CD", 400}, {"CM", 900}};

    int n = s.size(), res = 0;

    for (size_t i{}; i < n; ++i) {
      if (i + 1 < n and map.find(s.substr(i, 2)) != map.end()) {
        res += map[s.substr(i, 2)];
        ++i;
      } else {
        res += map[s.substr(i, 1)];
      }
    }

    return res;
  }
};

TEST_CASE("roman-to-integer", "[0013]") {
  Solution sol;
  string s("III");
  int output(3);
  CHECK(sol.romanToInt(s) == output);
}

TEST_CASE("roman-to-integer - 1", "[0013]") {
  Solution sol;
  string s("LVIII");
  int output(58);
  CHECK(sol.romanToInt(s) == output);
}

TEST_CASE("roman-to-integer - 2", "[0013]") {
  Solution sol;
  string s("MCMXCIV");
  int output(1994);
  CHECK(sol.romanToInt(s) == output);
}
