
#include <assert.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int minCostClimbingStairs(const vector<int> &cost) {
    vector<int> dp = cost;
    for (int i = 2; i < cost.size(); i++) {
      dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    return min(dp[cost.size() - 1], dp[cost.size() - 2]);
  }
};

int main() {

  Solution sol;
  vector<int> cost = {10, 15, 20};
  int ans = sol.minCostClimbingStairs(cost);
  std::cout << "ans = " << ans << endl;
  assert(ans == 15);

  return 0;
}
