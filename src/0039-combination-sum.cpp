
#include "leetcode.hpp"

class Solution {
public:
  void backtrack(int remain, vector<int> comb, vector<vector<int>> &result, vector<int> &candidates, int idx) {
    // solution found
    if (remain == 0) {
      result.push_back(comb);
      return;
    }

    // no solution
    if (remain < 0) {
      return;
    }

    for (int i = idx; i < candidates.size(); ++i) {
      // select
      comb.push_back(candidates[i]);
      backtrack(remain - candidates[i], comb, result, candidates, i);

      // undo the selection
      comb.erase(comb.end() - 1);
    }
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<int> combination{};
    vector<vector<int>> result{};
    backtrack(target, combination, result, candidates, 0);
    return result;
  }
};


TEST_CASE("combination-sum", "[0039]") {
  Solution s;
  int t = 8;
  vector<int> c = {3, 4, 5};
  vector<vector<int>> ans{{3, 5}, {4, 4}};

  REQUIRE(s.combinationSum(c, t) == ans);
}
