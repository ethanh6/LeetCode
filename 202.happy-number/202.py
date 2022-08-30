
class Solution:
    def isHappy(self, n: int) -> bool:
        def get_next(n) -> int:
            res = 0
            while n > 9:
                res += (n % 10) ** 2
                n = n // 10
            return res + n * n

        seen = set()

        while True:
            if n in seen:
                return False
            if n == 1:
                return True

            seen.add(n)
            n = get_next(n)
            print(n)


sol = Solution()
myans = sol.isHappy(19)
print(myans)
