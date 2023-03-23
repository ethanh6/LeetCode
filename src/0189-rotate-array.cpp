#include "leetcode.hpp"

class Solution {
public:
  void mirror(vector<int> &nums, int left, int right) {
    while (left <= right) {
      swap(nums[left++], nums[right--]);
    }
  }

  void rotate(vector<int> &nums, int k) { 
    k %= nums.size();
    mirror(nums, 0, nums.size() - 1);
    mirror(nums, 0, k - 1);
    mirror(nums, k, nums.size() - 1);
  }
};

TEST_CASE("rotate-array", "[0189]") {
  Solution s;

  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;
  s.rotate(nums, k);
  REQUIRE(nums == vector<int>{5, 6, 7, 1, 2, 3, 4});
}

TEST_CASE("rotate-array - 1", "[0189]") {
  Solution s;

  vector<int> nums = {-1, -100, 3, 99};
  int k = 2;
  s.rotate(nums, k);
  REQUIRE(nums == vector<int>{3, 99, -1, -100});
}
