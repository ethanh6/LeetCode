/*
You are given an array of strings `tokens` that represents an arithmetic
expression in a [Reverse Polish
Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation).

Evaluate the expression. Return _an integer that represents the value of the
expression_.

 **Note** that:

  * The valid operators are `'+'`, `'-'`, `'*'`, and `'/'`.
  * Each operand may be an integer or another expression.
  * The division between two integers always **truncates toward zero**.
  * There will not be any division by zero.
  * The input represents a valid arithmetic expression in a reverse polish
notation.
  * The answer and all the intermediate calculations can be represented in a
**32-bit** integer.

 **Example 1:**



     **Input:** tokens = ["2","1","+","3","*"] **Output:** 9 **Explanation:**
((2 + 1) * 3) = 9

 **Example 2:**



     **Input:** tokens = ["4","13","5","/","+"] **Output:** 6 **Explanation:**
(4 + (13 / 5)) = 6

 **Example 3:**



     **Input:** tokens =
["10","6","9","3","+","-11","*","/","*","17","+","5","+"] **Output:** 22
**Explanation:** ((10 * (6 / ((9 + 3) * -11))) + 17) + 5= ((10 * (6 / (12 *
-11))) + 17) + 5= ((10 * (6 / -132)) + 17) + 5= ((10 * 0) + 17) + 5= (0 + 17) +
5= 17 + 5= 22

 **Constraints:**

  * `1 <= tokens.length <= 104`
  * `tokens[i]` is either an operator: `"+"`, `"-"`, `"*"`, or `"/"`, or an
integer in the range `[-200, 200]`.


*/

#include "leetcode.hpp"

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> st;
    set<string> operators{"+", "-", "*", "/"};
    for (const auto &token : tokens) {
      if (operators.find(token) == operators.end()) {
        // number
        st.push(stoi(token));
      } else {
        // operator
        int n1 = st.top();
        st.pop();
        int n2 = st.top();
        st.pop();
        if (token == "+")
          st.push(n1 + n2);
        else if (token == "-")
          st.push(n2 - n1);
        else if (token == "*")
          st.push(n1 * n2);
        else if (token == "/")
          st.push(n2 / n1);
      }
    }
    return st.top();
  }
};

TEST_CASE("evaluate-reverse-polish-notation", "[0150]") {
  Solution sol;
  vector<string> tokens = {"2", "1", "+", "3", "*"};
  int output = 9;
  CHECK(sol.evalRPN(tokens) == output);
}

TEST_CASE("evaluate-reverse-polish-notation - 1", "[0150]") {
  Solution sol;
  vector<string> tokens = {"4", "13", "5", "/", "+"};
  int output = 6;
  CHECK(sol.evalRPN(tokens) == output);
}

TEST_CASE("evaluate-reverse-polish-notation - 2", "[0150]") {
  Solution sol;
  vector<string> tokens = {"10", "6", "9",  "3", "+", "-11", "*",
                           "/",  "*", "17", "+", "5", "+"};
  int output = 22;
  CHECK(sol.evalRPN(tokens) == output);
}
