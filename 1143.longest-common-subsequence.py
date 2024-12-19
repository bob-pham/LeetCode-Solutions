# @leet start
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text2), len(text1)
        grid = [[0 for _ in text1] for _ in text2]

        for y in range(m):
            for x in range(n):
                left = 0 if x - 1 < 0 else grid[y][x-1]
                top = 0 if y - 1 < 0 else grid[y-1][x]
                tl = 0 if y - 1 < 0 or x - 1 < 0 else grid[y-1][x-1]
                if text1[x] == text2[y]:
                   tl += 1
                   grid[y][x] = tl
                else:
                    grid[y][x] = max(top, left)

        return grid[m-1][n-1]
        
# @leet end
