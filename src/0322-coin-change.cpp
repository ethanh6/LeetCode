/*
You are given an integer array `coins` representing coins of different
denominations and an integer `amount` representing a total amount of money.

Return _the fewest number of coins that you need to make up that amount_. If
that amount of money cannot be made up by any combination of the coins, return
`-1`.

You may assume that you have an infinite number of each kind of coin.

 **Example 1:**



     **Input:** coins = [1,2,5], amount = 11 **Output:** 3 **Explanation:** 11 =
5 + 5 + 1

 **Example 2:**



     **Input:** coins = [2], amount = 3 **Output:** -1

 **Example 3:**



     **Input:** coins = [1], amount = 0 **Output:** 0

 **Constraints:**

  * `1 <= coins.length <= 12`
  * `1 <= coins[i] <= 231 - 1`
  * `0 <= amount <= 104`


*/

#include "leetcode.hpp"

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    // theorical Max value
    // any combination can't be greater than amount + 1
    int Max = amount + 1;

    vector<int> dp(amount + 1, Max);
    dp[0] = 0;

    for (int i = 1; i < amount + 1; ++i) {
      for (auto &c : coins) {
        if (i >= c) {
          dp[i] = min(dp[i], dp[i - c] + 1);
        }
      }
    }

    return dp.back() == Max ? -1 : dp.back();
  }
};

TEST_CASE("coin-change", "[0322]") {
  Solution sol;
  vector<int> coins = {1, 2, 5};
  int amount = 11, output = 3;
  CHECK(sol.coinChange(coins, amount) == output);
}

TEST_CASE("coin-change - 1", "[0322]") {
  Solution sol;
  vector<int> coins = {2};
  int amount = 3, output = -1;
  CHECK(sol.coinChange(coins, amount) == output);
}

TEST_CASE("coin-change - 2", "[0322]") {
  Solution sol;
  vector<int> coins = {1};
  int amount = 0, output = 0;
  CHECK(sol.coinChange(coins, amount) == output);
}
