#include "leetcode.hpp"

class Solution {
public:
  int majorityElement(vector<int> &arr) {
    int curr{}, count{};

    for (const auto &n : arr) {
      if (count == 0) {
        curr = n;
      }
      count += (curr == n) ? 1 : -1;
    }

    return curr;
  }
};

TEST_CASE("majority-element", "[0169]") {
  Solution s;
  auto input = vector<int>{1, 1, 2, 2, 2, 2, 3, 4};
  REQUIRE(s.majorityElement(input) == 2);
}
