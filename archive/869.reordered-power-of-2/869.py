from typing import List
from collections import Counter


class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:

        def get_digits(n: int):
            res = []
            while n > 9:
                res.append(n % 10)
                n = n // 10
            res.append(n)
            res = Counter(res)
            return res

        # build lookup table of
        i, x = 0, 1
        lookup = {}
        while x <= 10 ** 9:
            lookup[i] = get_digits(x)
            x *= 2
            i += 1

        # for pow, val in lookup.items():
        #     print("2^{} = {}".format(pow, val))

        target = get_digits(n)
        for _, counter in lookup.items():
            if target == counter:
                return True
        return False


sol = Solution()
n = 1
myans = sol.reorderedPowerOf2(n)
assert myans
print("(1) passed")

n = 10
myans = sol.reorderedPowerOf2(n)
assert not myans
print("(2) passed")


