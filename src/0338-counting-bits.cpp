/*
Given an integer `n`, return _an array_`ans` _of length_`n + 1` _such that for
each_`i` __ (`0 <= i <= n`) _,_`ans[i]` _is the **number of**_`1` _ **' s** in
the binary representation of _`i`.

 **Example 1:**



     **Input:** n = 2 **Output:** [0,1,1] **Explanation:** 0 --> 01 --> 12 -->
10

 **Example 2:**



     **Input:** n = 5 **Output:** [0,1,1,2,1,2] **Explanation:** 0 --> 01 --> 12
--> 103 --> 114 --> 1005 --> 101

 **Constraints:**

  * `0 <= n <= 105`

 **Follow up:**

  * It is very easy to come up with a solution with a runtime of `O(n log n)`.
Can you do it in linear time `O(n)` and possibly in a single pass?
  * Can you do it without using any built-in function (i.e., like
`__builtin_popcount` in C++)?


*/

#include "leetcode.hpp"

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> res(n + 1, 0);
    for (size_t i = 1; i < n + 1; ++i) {
      res[i] = res[i >> 1] + (i & 1);
    }
    return res;
  }
};

TEST_CASE("counting-bits", "[0338]") {
  Solution sol;
  int n = 2;
  vector<int> output{0, 1, 1};
  CHECK(sol.countBits(n) == output);
}

TEST_CASE("counting-bits - 1", "[0338]") {
  Solution sol;
  int n = 5;
  vector<int> output{0, 1, 1, 2, 1, 2};
  CHECK(sol.countBits(n) == output);
}
