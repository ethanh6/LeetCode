/*
A phrase is a **palindrome** if, after converting all uppercase letters into
lowercase letters and removing all non-alphanumeric characters, it reads the
same forward and backward. Alphanumeric characters include letters and
numbers.

Given a string `s`, return `true` _if it is a **palindrome** , or _`false`
_otherwise_.

 **Example 1:**

    
    
     **Input:** s = "A man, a plan, a canal: Panama" **Output:** true **Explanation:** "amanaplanacanalpanama" is a palindrome.

 **Example 2:**

    
    
     **Input:** s = "race a car" **Output:** false **Explanation:** "raceacar" is not a palindrome.

 **Example 3:**

    
    
     **Input:** s = " " **Output:** true **Explanation:** s is an empty string "" after removing non-alphanumeric characters.Since an empty string reads the same forward and backward, it is a palindrome.

 **Constraints:**

  * `1 <= s.length <= 2 * 105`
  * `s` consists only of printable ASCII characters.


*/

#include "leetcode.hpp"

class Solution {
public:
    bool isPalindrome(string s) {
      for( int l = 0, r = s.size() - 1; l < r; l++, r--) {
        while (l < r and not isalnum(s[l])) {
          l++;
        }
        while (l < r and not isalnum(s[r])) {
          r--;
        }
        if (tolower(s[l]) != tolower(s[r])) {
          return false;
        }
      }

      return true;
    }
};

TEST_CASE("valid-palindrome", "[0125]"){
    Solution s;
    REQUIRE(s.isPalindrome(string("A man, a plan, a canal: Panama")));
    REQUIRE_FALSE(s.isPalindrome(string("race a car")));
    REQUIRE(s.isPalindrome(string(" ")));
}
