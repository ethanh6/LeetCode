
#include <assert.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int coinChange(const vector<int> &coins, int amount) {
    vector<int> result(amount + 1, 0);

    // edge case
    if (amount <= 0) {
      return 0;
    }

    // normal case
    for (int amt = 1; amt < amount + 1; amt++) {
      int minimum = INT_MAX;

      for (auto coin : coins) {
        if (amt - coin >= 0) {
          minimum = std::min(result[amt - coin], minimum);
        }
      }
      result[amt] = minimum + int(minimum != INT_MAX);
    }

    // edge case: no valid solution
    return result[amount] == INT_MAX ? -1 : result[amount];
  }
};

int main() {

  Solution sol;
  int ans;
  vector<int> input;

  // normal case
  input = {1, 2, 5};
  ans = sol.coinChange(input, 11);
  cout << ans << endl;
  cout << "test (1) passed" << endl;

  // edge case: amount >= 0 but no valid solution
  ans = sol.coinChange({2}, 3);
  assert(ans == -1);
  cout << "test (2) passed" << endl;

  // edge case: amount <= 0
  ans = sol.coinChange({1}, 0);
  assert(ans == 0);
  cout << "test (3) passed" << endl;

  return 0;
}
