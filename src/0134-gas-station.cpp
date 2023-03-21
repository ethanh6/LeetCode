#include "leetcode.hpp"

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

    int total_diff = 0;
    int start_idx = 0;
    int cur = 0;

    for (int i = 0; i < gas.size(); ++i) {
      total_diff += gas[i] - cost[i];
      cur += gas[i] - cost[i];
      if (cur < 0) {
        cur = 0;
        start_idx = i + 1;
      }
    }
    return total_diff < 0 ? -1 : start_idx;
  }
};

TEST_CASE("gas-station", "[0134]") {
  Solution s;
  vector<int> gas  = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};
  REQUIRE(s.canCompleteCircuit(gas, cost) == 3);
}

TEST_CASE("gas-station - 1", "[0134]") {
  Solution s;
  vector<int> gas = {2, 3, 4};
  vector<int> cost = {3, 4, 3};
  REQUIRE(s.canCompleteCircuit(gas, cost) == -1);
}

TEST_CASE("gas-station - 2", "[0134]") {
  Solution s;
  vector<int> gas = {5,1,2,3,4};
  vector<int> cost = {4,4,1,5,1};
  REQUIRE(s.canCompleteCircuit(gas, cost) == 4);
}

TEST_CASE("gas-station - 3", "[0134]") {
  Solution s;
  vector<int> gas  = {1, 4, 2, 5, 3};
  vector<int> cost = {3, 1, 4, 2, 5};
  REQUIRE(s.canCompleteCircuit(gas, cost) == 1);
}
