/*
Given a signed 32-bit integer `x`, return `x` _with its digits reversed_. If
reversing `x` causes the value to go outside the signed 32-bit integer range
`[-231, 231 - 1]`, then return `0`.

 **Assume the environment does not allow you to store 64-bit integers (signed
or unsigned).**

 **Example 1:**



     **Input:** x = 123 **Output:** 321

 **Example 2:**



     **Input:** x = -123 **Output:** -321

 **Example 3:**



     **Input:** x = 120 **Output:** 21

 **Constraints:**

  * `-231 <= x <= 231 - 1`


*/

#include "leetcode.hpp"

class Solution {
public:
  int reverse(int x) {

    int result = 0;

    int upper = INT_MAX / 10;
    int lower = INT_MIN / 10;

    for (; x; x /= 10) {
      if (result > upper or result < lower) {
        return 0; // overflows
      }

      result = result * 10 + x % 10;
    }

    return result;
  }
};

TEST_CASE("reverse-integer", "[0007]") {
  Solution sol;
  int x = 123, output = 321;
  CHECK(sol.reverse(x) == output);
}

TEST_CASE("reverse-integer - 1", "[0007]") {
  Solution sol;
  int x = -123, output = -321;
  CHECK(sol.reverse(x) == output);
}

TEST_CASE("reverse-integer - 2", "[0007]") {
  Solution sol;
  int x = 120, output = 21;
  CHECK(sol.reverse(x) == output);
}
