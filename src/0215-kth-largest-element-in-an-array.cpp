/*
Given an integer array `nums` and an integer `k`, return _the_ `kth` _largest
element in the array_.

Note that it is the `kth` largest element in the sorted order, not the `kth`
distinct element.

Can you solve it without sorting?

 **Example 1:**



     **Input:** nums = [3,2,1,5,6,4], k = 2 **Output:** 5

 **Example 2:**



     **Input:** nums = [3,2,3,1,2,4,5,5,6], k = 4 **Output:** 4

 **Constraints:**

  * `1 <= k <= nums.length <= 105`
  * `-104 <= nums[i] <= 104`


*/

#include "leetcode.hpp"

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (const auto &n : nums) {
      if (minHeap.size() < k) {
        minHeap.push(n); // fill the minHeap first
      } else if (minHeap.top() < n) {
        minHeap.pop(); // pop the smallest
        minHeap.push(n);
      }
    }
    return minHeap.top();
  }
};

TEST_CASE("kth-largest-element-in-an-array", "[0215]") {
  Solution sol;
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2, output = 5;
  CHECK(sol.findKthLargest(nums, k) == output);
}

TEST_CASE("kth-largest-element-in-an-array - 1", "[0215]") {
  Solution sol;
  vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  int k = 4, output = 4;
  CHECK(sol.findKthLargest(nums, k) == output);
}
