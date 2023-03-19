/*

ThreeSum will use twoSum as a sub-routine to address the problem.

First of all look at twoSum.

1. It need to be sorted to apply the two-pointer method.
2. `lo` and `hi` pointer.
3. `left` and `right` to store the current num. This is critical since
    we need to keep track of the current solution and update the pointer
    accordingly to avoid duplicate solutions.
4. Update `lo` and `hi` according to the relation of `sum` and `target`.
    Note that the additional while loop to update the pointers. The while
    loops are updating the ptrs to avoid duplicate solutions.
5. Remember to update the pointers when the solution is found.

Check out the threeSum solution.

It uses similar logic to twoSum.

Find out the two sum solution for each element, and add the triplet as solution.

To avoid duplicate solutions, increment `i` when there is a duplicate number.
*/

#include "leetcode.hpp"
class Solution {
public:
  vector<vector<int>> twoSum(vector<int> &nums, int start, int target) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    int lo = start;
    int hi = nums.size() - 1;
    int left, right, sum;

    while (lo < hi) {
      left = nums[lo];
      right = nums[hi];
      sum = left + right;
      // make sure there are no duplicates
      if (sum < target) {
        while (lo < hi && nums[lo] == left)
          lo++;
      } else if (sum > target) {
        while (lo < hi && nums[hi] == right)
          hi--;
      } else {
        ret.push_back({left, right});
        while (lo < hi && nums[lo] == left)
          lo++;
        while (lo < hi && nums[hi] == right)
          hi--;
      }
    }
    return ret;
  }

  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;

    for (int i = 0; i < nums.size(); i++) {
      // perform 2 sum with target = 0 - nums[i]
      vector<vector<int>> ts = twoSum(nums, i + 1, -nums[i]);

      // each triplet is a solution
      for (auto t : ts) {
        // triplet = {nums[i], t[0], t[1]};
        ret.emplace_back(vector<int>{nums[i], t[0], t[1]});
      }

      // update i to avoid duplicate nums[i]
      while (i < nums.size() && nums[i] == nums[i + 1]) {
        i++;
      }
    }

    return ret;
  }
};

TEST_CASE("3sum", "[0015]") {
  Solution s;
  vector<int> v{-1, 0, 1, 2, -1, -4};
  REQUIRE(s.threeSum(v) == vector<vector<int>>{{-1, -1, 2}, {-1, 0, 1}});
}

TEST_CASE("3sum - 1", "[0015]") {
  Solution s;
  vector<int> v{0, 0, 0};
  REQUIRE(s.threeSum(v) == vector<vector<int>>{{0, 0, 0}});
}

TEST_CASE("2sum", "[0015]") {
  Solution s;
  vector<int> v{3, 5, 2, 6};
  REQUIRE(s.twoSum(v, 0, 8) == vector<vector<int>>{{2, 6}, {3, 5}});
}
