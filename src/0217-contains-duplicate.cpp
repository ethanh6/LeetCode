#include "leetcode.hpp"

class Solution2 {
public:
  bool containsDuplicate(vector<int> &nums) {
    return nums.size() != unordered_set<int>(nums.begin(), nums.end()).size();
  };
};

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> s;
    for (auto n : nums) {
      if (s.count(n) > 0) {
        return true;
      } else {
        s.emplace(n);
      }
    }
    return false;
  }
};

TEST_CASE("contains-duplicate", "[0217]") {
  Solution s;
  vector<int> input{1, 2, 3, 1};
  REQUIRE(s.containsDuplicate(input));
  input = {1, 2, 3, 4};
  REQUIRE_FALSE(s.containsDuplicate(input));
}

TEST_CASE("contains-duplicate - 1", "[0217]") {
  Solution2 s;
  vector<int> input{1, 2, 3, 1};
  REQUIRE(s.containsDuplicate(input));
  input = {1, 2, 3, 4};
  REQUIRE_FALSE(s.containsDuplicate(input));
}
