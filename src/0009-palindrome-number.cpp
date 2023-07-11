/*
Given an integer `x`, return `true` _if_`x` _is a_ _ **palindrome**_ _,
and_`false` _otherwise_.

 **Example 1:**



     **Input:** x = 121 **Output:** true **Explanation:** 121 reads as 121 from
left to right and from right to left.

 **Example 2:**



     **Input:** x = -121 **Output:** false **Explanation:** From left to right,
it reads -121. From right to left, it becomes 121-. Therefore it is not a
palindrome.

 **Example 3:**



     **Input:** x = 10 **Output:** false **Explanation:** Reads 01 from right to
left. Therefore it is not a palindrome.

 **Constraints:**

 **Follow up:** Could you solve it without converting the integer to a string?


*/

#include "leetcode.hpp"

class Solution0 {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    string s = to_string(x);
    int n = s.size();
    for (size_t i{}; i < n / 2; ++i) {
      if (s[i] != s[n - 1 - i])
        return false;
    }
    return true;
  }
};

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0 or (x != 0 and x % 10 == 0))
      return false;

    int revertedHalf = 0;
    while (x > revertedHalf) {
      revertedHalf = revertedHalf * 10 + x % 10;
      x /= 10;
    }

    return x == revertedHalf or x == revertedHalf / 10;
  }
};

// TEST_CASE("palindrome-number", "[0009]") {
//   Solution sol;
//   CHECK(sol.isPalindrome(121));
// }
//
// TEST_CASE("palindrome-number - 1", "[0009]") {
//   Solution sol;
//   CHECK_FALSE(sol.isPalindrome(-121));
// }
//
// TEST_CASE("palindrome-number - 2", "[0009]") {
//   Solution sol;
//   CHECK_FALSE(sol.isPalindrome(10));
// }

TEST_CASE("palindrome-number - 3", "[0009]") {
  Solution sol;
  CHECK_FALSE(sol.isPalindrome(123));
}
