/*
Given a list of non-negative integers `nums`, arrange them such that they form
the largest number and return it.

Since the result may be very large, so you need to return a string instead of
an integer.

 **Example 1:**



     **Input:** nums = [10,2] **Output:** "210"

 **Example 2:**



     **Input:** nums = [3,30,34,5,9] **Output:** "9534330"

 **Constraints:**

  * `1 <= nums.length <= 100`
  * `0 <= nums[i] <= 109`


*/

#include "leetcode.hpp"

class Solution {
public:
  string largestNumber(vector<int> &nums) {
    vector<string> strs;
    for (const auto &n : nums)
      strs.emplace_back(to_string(n));

    auto comp = [&](const string &a, const string &b) { return a + b > b + a; };

    sort(strs.begin(), strs.end(), comp);

    string ans("");
    for (const auto &s : strs)
      ans += s;

    while (ans[0] == '0' && ans.size() > 1) {
      ans.erase(0, 1);
    }

    return ans;
  }
};

TEST_CASE("largest-number", "[0179]") {
  Solution sol;
  vector<int> nums = {10, 2};
  CHECK(sol.largestNumber(nums) == "210");
  nums = vector<int>{3, 30, 34, 5, 9};
  CHECK(sol.largestNumber(nums) == "9534330");
  nums = vector<int>{0, 0};
  CHECK(sol.largestNumber(nums) == "0");
}
