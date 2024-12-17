# @leet start
class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        grid = [[sys.maxsize for _ in range(n)] for _ in range(m)]

        for x in range(n):
            grid[0][x] = matrix[0][x]
        
        for y in range(1, m):
            for x in range(n):
                if x - 1 >= 0:
                    grid[y][x] = min(grid[y][x], matrix[y][x] + grid[y-1][x-1])
                if x + 1 < n:
                    grid[y][x] = min(grid[y][x], matrix[y][x] + grid[y-1][x+1])
                grid[y][x] = min(grid[y][x], matrix[y][x] + grid[y-1][x])

        return min(grid[-1])
# @leet end

