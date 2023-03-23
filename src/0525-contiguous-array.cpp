#include "leetcode.hpp"

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      unordered_map<int, int> m {{0, -1}};
      int counter = 0, ans = 0;

      for(int i = 0; i < nums.size(); ++i) {
        counter += nums[i] == 1 ? 1 : -1;
        if (m.count(counter) != 0) {
          ans = max(ans, i - m[counter]);
        } else {
          m[counter] = i;
        }
      }
      return ans;
    }
};

TEST_CASE("contiguous-array", "[0525]"){
    Solution s;
    vector<int> nums {0, 1};
    CHECK(s.findMaxLength(nums) == 2);

    nums = {0, 1, 0};
    CHECK(s.findMaxLength(nums) == 2);

    nums = {0, 1, 1, 0};
    CHECK(s.findMaxLength(nums) == 4);

    nums = {0,0,1,0,0,0,1,1};
    CHECK(s.findMaxLength(nums) == 6);
    
    nums = {0,1,1,1,1};
    CHECK(s.findMaxLength(nums) == 2);
}
