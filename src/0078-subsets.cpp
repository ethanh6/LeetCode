/*
Given an integer array `nums` of **unique** elements, return _all possible_
_subsets_ _(the power set)_.

The solution set **must not** contain duplicate subsets. Return the solution
in **any order**.

 **Example 1:**



     **Input:** nums = [1,2,3] **Output:**
[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

 **Example 2:**



     **Input:** nums = [0] **Output:** [[],[0]]

 **Constraints:**

  * `1 <= nums.length <= 10`
  * `-10 <= nums[i] <= 10`


*/

#include "leetcode.hpp"

class Solution_0 {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans{};

    std::function<void(int, vector<int>)> dfs = [&](int idx, vector<int> path) {
      ans.push_back(path);
      for (int i = idx; i < nums.size(); ++i) {
        path.push_back(nums[i]);
        dfs(i + 1, path);
        path.pop_back();
      }
    };

    dfs(0, vector<int>{});

    return ans;
  }
};

class Solution_1 {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans{{}};
    for (int num: nums) {
      int size = ans.size();
      for (int i = 0; i < size; ++i) {
        ans.push_back(ans[i]);
        ans.back().push_back(num);
      }
    }
    return ans;
  }
};

TEST_CASE("subsets", "[0078]") {
  Solution_1 sol;

  vector<int> nums = {1, 2, 3};
  vector<vector<int>> output{{},  {1},    {2},    {1, 2},
                             {3}, {1, 3}, {2, 3}, {1, 2, 3}};
  CHECK(sol.subsets(nums).size() == output.size());
  CHECK(sol.subsets(nums) == output);
}
