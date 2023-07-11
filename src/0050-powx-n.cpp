/*
Implement [pow(x, n)](http://www.cplusplus.com/reference/valarray/pow/), which
calculates `x` raised to the power `n` (i.e., `xn`).

 **Example 1:**



     **Input:** x = 2.00000, n = 10 **Output:** 1024.00000

 **Example 2:**



     **Input:** x = 2.10000, n = 3 **Output:** 9.26100

 **Example 3:**



     **Input:** x = 2.00000, n = -2 **Output:** 0.25000 **Explanation:** 2-2 =
1/22 = 1/4 = 0.25

 **Constraints:**

  * `-100.0 < x < 100.0`
  * `-231 <= n <= 231-1`
  * `n` is an integer.
  * Either `x` is not zero or `n > 0`.
  * `-104 <= xn <= 104`


*/

#include "leetcode.hpp"

class Solution {
public:
  double myPow(double x, int n) {

    std::function<double(double, int)> helper = [&](double x, int n) -> double {
      if (n == 0) return 1;

      auto half = helper(x, n / 2);
      return half * half * (n & 1 ? x : 1);
    };

    // making sure n >= 0
    if (n < 0) {
      x = 1 / x;
      n = -n;
    }

    return helper(x, n);
  }
};

TEST_CASE("powx-n", "[0050]") {
  Solution sol;
  double x = 2.00000, n = 10;
  double output = 1024.00000;
  CHECK(sol.myPow(x, n) == output);
}

TEST_CASE("powx-n - 1", "[0050]") {
  Solution sol;
  double x = 2.10000, n = 3;
  double output = 9.26100;
  CHECK(sol.myPow(x, n) == output);
}

TEST_CASE("powx-n - 2", "[0050]") {
  Solution sol;
  double x = 2.00000, n = -2;
  double output = 0.25000;
  CHECK(sol.myPow(x, n) == output);
}
