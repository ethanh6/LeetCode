/*
Given an integer array `nums` sorted in **non-decreasing order** , remove some
duplicates [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm)
such that each unique element appears **at most twice**. The **relative
order** of the elements should be kept the **same**.

Return `k` _after placing the final result in the first_`k` _slots of_`nums`.

Do **not** allocate extra space for another array. You must do this by
**modifying the input array[in-place](https://en.wikipedia.org/wiki/In-
place_algorithm)** with O(1) extra memory.

 **Custom Judge:**

The judge will test your solution with the following code:



    int[] nums = [...]; // Input arrayint[] expectedNums = [...]; // The
expected answer with correct lengthint k = removeDuplicates(nums); // Calls your
implementationassert k == expectedNums.length;for (int i = 0; i < k; i++) {
assert nums[i] == expectedNums[i];}

If all assertions pass, then your solution will be **accepted**.

 **Example 1:**



     **Input:** nums = [1,1,1,2,2,3] **Output:** 5, nums = [1,1,2,2,3,_]
**Explanation:** Your function should return k = 5, with the first five elements
of nums being 1, 1, 2, 2 and 3 respectively.It does not matter what you leave
beyond the returned k (hence they are underscores).

 **Example 2:**



     **Input:** nums = [0,0,1,1,1,1,2,3,3] **Output:** 7, nums =
[0,0,1,1,2,3,3,_,_] **Explanation:** Your function should return k = 7, with the
first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.It does
not matter what you leave beyond the returned k (hence they are underscores).

 **Constraints:**

  * `1 <= nums.length <= 3 * 104`
  * `-104 <= nums[i] <= 104`
  * `nums` is sorted in **non-decreasing** order.


*/

#include "leetcode.hpp"

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() < 2)
      return nums.size();
    int insertPos = 2;

    for (size_t i{2}; i < nums.size(); ++i) {
      if (nums[i] != nums[insertPos - 2]) {
        nums[insertPos++] = nums[i];
      }
    }

    return insertPos;
  }
};

TEST_CASE("remove-duplicates-from-sorted-array-ii", "[0080]") {
  Solution sol;
  CHECK(true);
}
