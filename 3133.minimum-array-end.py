# @leet start
import math

class Solution:
    def minEnd(self, n: int, x: int) -> int:
        left_one = x.bit_length()
        num_0 = bin(x)[2:].count("0")
        n -= num_0
        if (n <= 0):
            return x
        return (x | ((n - 1) << (left_one + 1)))
# @leet end
