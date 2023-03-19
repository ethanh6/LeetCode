#include "leetcode.hpp"

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int profit = 0, low = prices[0];
    for (auto &p : prices) {
      low = p < low ? p : low;
      profit = p - low > profit ? p - low : profit;
    }
    return profit;
  }
};

TEST_CASE("best-time-to-buy-and-sell-stock", "[0121]") {
  Solution s;
  vector<int> p1{7, 1, 5, 3, 6, 4};
  REQUIRE(s.maxProfit(p1) == 5);

  vector<int> p2{7, 6, 4, 3, 1};
  REQUIRE(s.maxProfit(p2) == 0);
}
