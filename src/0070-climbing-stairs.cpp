/*
You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways can
you climb to the top?

 **Example 1:**

    
    
     **Input:** n = 2 **Output:** 2 **Explanation:** There are two ways to climb to the top.1. 1 step + 1 step2. 2 steps

 **Example 2:**

    
    
     **Input:** n = 3 **Output:** 3 **Explanation:** There are three ways to climb to the top.1. 1 step + 1 step + 1 step2. 1 step + 2 steps3. 2 steps + 1 step

 **Constraints:**

  * `1 <= n <= 45`


*/

#include "leetcode.hpp"

class Solution {
public:
    int climbStairs(int n) {
      if (n <= 2) return n;
      int a = 1, b = 2, k = n - 2;
      while (k--) {
        int tmp = a + b;
        a = b;
        b = tmp;
      }
      return b;
    }
};

TEST_CASE("climbing-stairs", "[0070]"){
    Solution sol;
    CHECK(sol.climbStairs(2) == 2);
    CHECK(sol.climbStairs(3) == 3);
}
