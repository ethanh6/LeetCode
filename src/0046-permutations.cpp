/*
Given an array `nums` of distinct integers, return _all the possible
permutations_. You can return the answer in **any order**.

 **Example 1:**



     **Input:** nums = [1,2,3] **Output:**
[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

 **Example 2:**



     **Input:** nums = [0,1] **Output:** [[0,1],[1,0]]

 **Example 3:**



     **Input:** nums = [1] **Output:** [[1]]

 **Constraints:**

  * `1 <= nums.length <= 6`
  * `-10 <= nums[i] <= 10`
  * All the integers of `nums` are **unique**.


*/

#include "leetcode.hpp"

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {

    int n = nums.size();
    vector<vector<int>> output;

    function<void(int)> backtrack = [&](int idx) -> void {
      if (idx == nums.size())
        output.push_back(nums);

      for (int i = idx; i < n; ++i) {
        swap(nums[idx], nums[i]);
        backtrack(idx + 1);
        swap(nums[idx], nums[i]);
      }
    };

    backtrack(0);

    return output;
  }
};

TEST_CASE("permutations", "[0046]") {
  Solution sol;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> output{{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                             {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
  CHECK(sol.permute(nums) == output);
}
