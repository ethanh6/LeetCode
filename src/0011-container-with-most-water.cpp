#include "leetcode.hpp"

class Solution {
public:
  int maxArea(vector<int> &height) {
    int L = 0, R = height.size() - 1;
    int result = 0;

    while (L < R) {
      result = max(result, min(height[L], height[R]) * (R - L));
      if (height[L] < height[R]) {
        L++;
      } else {
        R--;
      }
    }

    return result;
  }
};

TEST_CASE("container-with-most-water", "[0011]") {
  Solution s;
  vector<int> input{1, 8, 6, 2, 5, 4, 8, 3, 7};
  REQUIRE(s.maxArea(input) == 49);
  input = vector<int>{1, 3};
  REQUIRE(s.maxArea(input) == 1);
}
