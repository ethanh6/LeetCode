/*
Given a string containing digits from `2-9` inclusive, return all possible
letter combinations that the number could represent. Return the answer in
**any order**.

A mapping of digits to letters (just like on the telephone buttons) is given
below. Note that 1 does not map to any letters.

![](https://assets.leetcode.com/uploads/2022/03/15/1200px-telephone-
keypad2svg.png)

 **Example 1:**



     **Input:** digits = "23" **Output:**
["ad","ae","af","bd","be","bf","cd","ce","cf"]

 **Example 2:**



     **Input:** digits = "" **Output:** []

 **Example 3:**



     **Input:** digits = "2" **Output:** ["a","b","c"]

 **Constraints:**

  * `0 <= digits.length <= 4`
  * `digits[i]` is a digit in the range `['2', '9']`.


*/

#include "leetcode.hpp"

class Solution {
public:
  unordered_map<char, vector<char>> m = {
      {
          '2',
          {'a', 'b', 'c'},
      },
      {
          '3',
          {'d', 'e', 'f'},
      },
      {
          '4',
          {'g', 'h', 'i'},
      },
      {
          '5',
          {'j', 'k', 'l'},
      },
      {
          '6',
          {'m', 'n', 'o'},
      },
      {
          '7',
          {'p', 'q', 'r', 's'},
      },
      {
          '8',
          {'t', 'u', 'v'},
      },
      {
          '9',
          {'w', 'x', 'y', 'z'},
      },
  };

  vector<string> letterCombinations(string digits) {
    vector<string> output;

    if (digits.size() == 0)
      return {};

    std::function<void(int, string)> backtrack = [&](int index, string path) -> void {
      // terminal condition
      if (path.size() == digits.size()) {
        output.push_back(path);
        return;
      }

      char digit = digits[index];
      for (const char &c : m[digit]) {
        backtrack(index + 1, path + c);
      }
    };

    backtrack(0, string(""));

    return output;
  }
};

TEST_CASE("letter-combinations-of-a-phone-number", "[0017]") {
  Solution sol;
  string digits = "23";
  vector<string> output{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce",
  "cf"}; CHECK(sol.letterCombinations(digits) == output);
}

TEST_CASE("letter-combinations-of-a-phone-number - 1", "[0017]") {
  Solution sol;
  string digits = "";
  vector<string> output;
  CHECK(sol.letterCombinations(digits) == output);
}

TEST_CASE("letter-combinations-of-a-phone-number - 2", "[0017]") {
  Solution sol;
  string digits = "2";
  vector<string> output{"a", "b", "c"};
  CHECK(sol.letterCombinations(digits) == output);
}
