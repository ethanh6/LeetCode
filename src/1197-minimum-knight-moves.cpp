#include "leetcode.hpp"

class Solution {
public:
  int minKnightMoves(int x, int y) {

    // only store coordinates where x <= y
    unordered_map<string, int> dp{{"0,0", 0}, {"0,1", 3}, {"0,2", 2},
                                  {"1,0", 3}, {"1,1", 2}, {"1,2", 1},
                                  {"2,0", 2}, {"2,1", 1}, {"2,2", 4}};

    std::function<int(int, int)> dfs = [&](int x, int y) {
      // make sure that x <= y
      if (x > y) {
        swap(x, y);
      }

      string key = to_string(x) + "," + to_string(y);

      if (dp.find(key) != dp.end()) {
        return dp[key];
      }
      return dp[key] = 1 + min(dfs(abs(x - 1), abs(y - 2)),
                               dfs(abs(x - 2), abs(y - 1)));
    };

    return dfs(abs(x), abs(y));
  }
};

TEST_CASE("minimum-knight-moves", "[1197]") {
  Solution sol;
  int x = 2, y = 1, output = 1;
  CHECK(sol.minKnightMoves(x, y) == output);
}

TEST_CASE("minimum-knight-moves - 1", "[1197]") {
  Solution sol;
  int x = 5, y = 5, output = 4;
  CHECK(sol.minKnightMoves(x, y) == output);
}

TEST_CASE("minimum-knight-moves - 2", "[1197]") {
  Solution sol;
  int x = 2, y = 112, output = 56;
  CHECK(sol.minKnightMoves(x, y) == output);
}
