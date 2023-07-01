/*
Define a pair `(u, v)` which consists of one element from the first array and
one element from the second array.

Return _the_ `k` _pairs_ `(u1, v1), (u2, v2), ..., (uk, vk)` _with the
smallest sums_.

 **Example 1:**



     **Input:** nums1 = [1,7,11], nums2 = [2,4,6], k = 3 **Output:**
[[1,2],[1,4],[1,6]] **Explanation:** The first 3 pairs are returned from the
sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

 **Example 2:**



     **Input:** nums1 = [1,1,2], nums2 = [1,2,3], k = 2 **Output:**
[[1,1],[1,1]] **Explanation:** The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

 **Example 3:**



     **Input:** nums1 = [1,2], nums2 = [3], k = 3 **Output:** [[1,3],[2,3]]
**Explanation:** All possible pairs are returned from the sequence: [1,3],[2,3]

 **Constraints:**

  * `1 <= nums1.length, nums2.length <= 105`
  * `-109 <= nums1[i], nums2[i] <= 109`
  * `nums1` and `nums2` both are sorted in **non-decreasing order**.
  * `1 <= k <= 104`


*/

#include "leetcode.hpp"

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    using triplet = std::tuple<int, int, int>; // (sum, nums[i], nums[j])
    std::priority_queue<triplet, vector<triplet>> maxHeap;

    for (int i = 0; i < nums1.size(); ++i) {
      for (int j = 0; j < nums2.size(); ++j) {
        int sum = nums1[i] + nums2[j];

        if (maxHeap.size() < k) { // when heap is not full
          maxHeap.push(make_tuple(sum, nums1[0], nums2[0]));
        }
        else if (sum < std::get<0>(maxHeap.top())) { // heap full, replace element
          maxHeap.pop();
          maxHeap.push(make_tuple(sum, nums1[0], nums2[0]));
        }
        else {
          break; // don't need to traverse the rest of nums2
        }
      }
    }

    vector<vector<int>> res;
    for (; !maxHeap.empty(); maxHeap.pop()) {
      auto top = maxHeap.top();
      res.insert(res.begin(), {get<1>(top), get<2>(top)});
    }
    return res;
  }
};

TEST_CASE("find-k-pairs-with-smallest-sums", "[0373]") {
  Solution sol;
  vector<int> nums1{1, 7, 11}, nums2{2, 4, 6};
  int k = 3;
  vector<vector<int>> output{{1, 2}, {1, 4}, {1, 6}};
  CHECK(sol.kSmallestPairs(nums1, nums2, k) == output);
}

TEST_CASE("find-k-pairs-with-smallest-sums - 1", "[0373]") {
  Solution sol;
  vector<int> nums1{1, 1, 2}, nums2{1, 2, 3};
  int k = 2;
  vector<vector<int>> output{{1, 1}, {1, 1}};
  CHECK(sol.kSmallestPairs(nums1, nums2, k) == output);
}
