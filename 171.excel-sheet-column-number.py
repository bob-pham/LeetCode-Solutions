# @leet start
class Solution:
    def charToNum(self, c: str) -> int:
        return 1 + (ord(c) - ord('A'))

    def titleToNumber(self, columnTitle: str) -> int:
        base = 1
        result = 0
        for i in range(len(columnTitle) - 1, -1, -1):
            result += self.charToNum(columnTitle[i]) * base
            base *= 26

        return result
# @leet end
