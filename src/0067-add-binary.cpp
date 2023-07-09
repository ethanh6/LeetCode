/*
Given two binary strings `a` and `b`, return _their sum as a binary string_.

 **Example 1:**



     **Input:** a = "11", b = "1" **Output:** "100"

 **Example 2:**



     **Input:** a = "1010", b = "1011" **Output:** "10101"

 **Constraints:**

  * `1 <= a.length, b.length <= 104`
  * Each string does not contain leading zeros except for the zero itself.


*/

#include "leetcode.hpp"

class Solution {
public:
  string addBinary(string a, string b) {
    string res;

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while (i >= 0 or j >= 0 or carry > 0) {
      if (i >= 0)
        carry += a[i--] - '0';

      if (j >= 0)
        carry += b[j--] - '0';

      res += (carry % 2 == 1) ? '1' : '0';
      carry /= 2;
    }

    reverse(res.begin(), res.end());
    return res;
  }
};

TEST_CASE("add-binary", "[0067]") {
  Solution sol;
  string a("11"), b("1"), output("100");
  CHECK(sol.addBinary(a, b) == output);
}

TEST_CASE("add-binary - 1", "[0067]") {
  Solution sol;
  string a("1010"), b("1011"), output("10101");
  CHECK(sol.addBinary(a, b) == output);
}
