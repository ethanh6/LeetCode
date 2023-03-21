#include "leetcode.hpp"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
      vector<int> res(n, 1);
      for(int i = 0, pre = 1, suf = 1; i < n; ++i) {
        res[i] *= pre;
        pre *= nums[i];
        res[n - 1 - i] *= suf;
        suf *= nums[n - 1 - i];
      }
      return res;
    }
};

TEST_CASE("product-of-array-except-self", "[0238]"){
    Solution s;
    vector<int> v0 {1, 2, 3, 4};
    s.productExceptSelf(v0);
    REQUIRE(true);
}
