/*
The integer division should truncate toward zero.
You may assume that the given expression is always valid. All intermediate
results will be in the range of `[-231, 231 - 1]`.

 **Note:** You are not allowed to use any built-in function which evaluates
strings as mathematical expressions, such as `eval()`.

 **Example 1:**



     **Input:** s = "3+2*2" **Output:** 7

 **Example 2:**



     **Input:** s = " 3/2 " **Output:** 1

 **Example 3:**



     **Input:** s = " 3+5 / 2 " **Output:** 5

 **Constraints:**

  * `1 <= s.length <= 3 * 105`
  * `s` consists of integers and operators `('+', '-', '*', '/')` separated by
some number of spaces.
  * `s` represents **a valid expression**.
  * All the integers in the expression are non-negative integers in the range
`[0, 231 - 1]`.
  * The answer is **guaranteed** to fit in a **32-bit integer**.


*/

#include "leetcode.hpp"

class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if (len == 0) return 0;
        stack<int> stack;
        int currentNumber = 0;
        char operation = '+';
        for (int i = 0; i < len; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if ((!isdigit(currentChar) && !iswspace(currentChar)) || i == len - 1) {
                if (operation == '-') {
                    stack.push(-currentNumber);
                } else if (operation == '+') {
                    stack.push(currentNumber);
                } else if (operation == '*') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop * currentNumber);
                } else if (operation == '/') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNumber);
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        int result = 0;
        while (stack.size() != 0) {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};

TEST_CASE("basic-calculator-ii", "[0227]") {
  Solution sol;
  string s = "3+2*2";
  CHECK(sol.calculate(s) == 7);
}

TEST_CASE("basic-calculator-ii - 1", "[0227]") {
  Solution sol;
  string s = "3/2";
  CHECK(sol.calculate(s) == 1);
}

TEST_CASE("basic-calculator-ii - 2", "[0227]") {
  Solution sol;
  string s = "3 + 5  / 2";
  CHECK(sol.calculate(s) == 5);
}

TEST_CASE("basic-calculator-ii - 3", "[0227]") {
  Solution sol;
  string s = "3 + 5 * 9 / 2 - 8";
  CHECK(sol.calculate(s) == 17);
}
