from typing import List


class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"

        num1 = num1[::-1]
        num2 = num2[::-1]

        products = [self.multiply_single_digits(num2, n, i) for i, n in enumerate(num1)]
        sum_result = self.sum_results(products)

        res = ""
        for n in sum_result[::-1]:
            res += str(n)

        return res

    def sum_results(self, numbers: List[List[int]]):
        # match size of each list
        longest = max(numbers, key=len)
        for i in range(len(numbers)):
            numbers[i] += [0] * (len(longest) - len(numbers[i]))

        # add the numbers
        res = []
        carry = 0

        for i, _ in enumerate(longest):
            x = sum([n[i] for n in numbers]) + carry
            carry = x // 10
            res.append(x % 10)
        if carry:
            res.append(carry)

        return res

    def multiply_single_digits(self, number, multiplier, leading_zeros) -> List[int]:
        carry = 0
        res = [0] * leading_zeros

        for n in number:
            prod = int(n) * int(multiplier) + carry

            d = prod % 10
            carry = prod // 10

            res.append(d)

        if carry:
            res.append(carry)

        return res


sol = Solution()
n1 = "456"
n2 = "123"
myans = sol.multiply(n1, n2)
assert myans == "56088"
print("(1) passed")
