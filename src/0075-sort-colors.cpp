#include "leetcode.hpp"

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int L = 0, R = nums.size() - 1, cur = 0;
    while (cur <= R) {
      if (nums[cur] == 0) {
        swap(nums[L++], nums[cur++]);
      } else if (nums[cur] == 1) {
        cur++;
      } else if (nums[cur] == 2) {
        swap(nums[R--], nums[cur]);
      }
    }
  }
};

TEST_CASE("swap") {
  vector<int> v{1, 2};
  swap(v[0], v[1]);
  CHECK(v == vector<int>{2,1});
}

TEST_CASE("sort-colors", "[0075]") {
  Solution s;
  vector<int> colors{2, 0, 2, 1, 1, 0};
  s.sortColors(colors);
  REQUIRE(colors == vector<int>{0, 0, 1, 1, 2, 2});
}

TEST_CASE("sort-colors - 1", "[0075]") {
  Solution s;
  vector<int> colors{2, 0, 1};
  s.sortColors(colors);
  REQUIRE(colors == vector<int>{0, 1, 2});
}
