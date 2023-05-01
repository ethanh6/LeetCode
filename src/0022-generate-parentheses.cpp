/*
Given `n` pairs of parentheses, write a function to _generate all combinations
of well-formed parentheses_.

 **Example 1:**



     **Input:** n = 3 **Output:** ["((()))","(()())","(())()","()(())","()()()"]

 **Example 2:**



     **Input:** n = 1 **Output:** ["()"]

 **Constraints:**

  * `1 <= n <= 8`


*/

#include "leetcode.hpp"

class Solution_backtrack {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> output;
    if (!n)
      return output;
    std::function<void(string, int, int)> backtrack =
        [&](string cur_str, int left_count, int right_count) -> void {


          // terminal condition
      if (cur_str.size() == n * 2) {
        output.push_back(cur_str);
        return;
      }


      // if there are more '(' to add
      if (left_count < n) {
        cur_str.push_back('(');
        backtrack(cur_str, left_count + 1, right_count);
        cur_str.pop_back();
      }

      // if there are more ')' to add
      if (right_count < left_count) {
        cur_str.push_back(')');
        backtrack(cur_str, left_count, right_count + 1);
        cur_str.pop_back();
      }
    };

    backtrack("", 0, 0);
    return output;
  }
};

TEST_CASE("generate-parentheses", "[0022]") {
  Solution sol;
  int n = 3;
  vector<string> output{"((()))", "(()())", "(())()", "()(())", "()()()"};
  CHECK(sol.generateParenthesis(n) == output);
}

TEST_CASE("generate-parentheses - 1", "[0022]") {
  Solution sol;
  int n = 1;
  vector<string> output{"()"};
  CHECK(sol.generateParenthesis(n) == output);
}
