from typing import List


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow, fast = nums[0], nums[0]

        # exit condition: cycle detected
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break

        slow = nums[0]
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]

        return fast


sol = Solution()
nums = [1, 3, 4, 2, 2]
myans = sol.findDuplicate(nums)
assert myans == 2
print("(1) passed")

nums = [3, 1, 3, 4, 2]
myans = sol.findDuplicate(nums)
assert myans == 3
print("(2) passed")

nums = [2, 1, 1]
myans = sol.findDuplicate(nums)
assert myans == 1
print("(3) passed")
