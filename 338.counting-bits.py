# @leet start
class Solution:
    def countBits(self, n: int) -> List[int]:
        res = []
        for i in range(n+1):
            c = 0
            for _ in range(64):
                if i & 0x1 == 0x1:
                    c += 1
                i = i >> 1
            res.append(c)

        return res

        
# @leet end
