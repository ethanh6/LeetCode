from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        _max = float("inf")

        dp = [_max for _ in range(amount + 1)]
        dp[0] = 0

        for i in range(1, amount + 1):
            dp[i] = min(dp[i - c] for c in coins if i >= c) + 1

        if dp[-1] == _max:
            return -1
        else:
            return dp[-1]


sol = Solution()
myans = sol.coinChange([1, 2, 5], 11)
assert myans == 3
print("(1) passed")

myans = sol.coinChange([2], 3)
assert myans == -1
print("(2) passed")

myans = sol.coinChange([1], 0)
assert myans == 0
print("(3) passed")
