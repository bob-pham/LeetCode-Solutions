# @leet start
from collections import deque


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        num_islands = 0

        for y in range(m):
            for x in range(n):
                if grid[y][x] == "1":
                    num_islands += 1

                    queue = deque()
                    queue.appendleft((y, x))

                    while len(queue) > 0:
                        yi, xi = queue.pop()

                        if grid[yi][xi] == "0":
                            continue

                        grid[yi][xi] = "0"

                        if yi - 1 >= 0 and grid[yi - 1][xi] == "1":
                            queue.appendleft((yi - 1, xi))

                        if yi + 1 < m and grid[yi + 1][xi] == "1":
                            queue.appendleft((yi + 1, xi))

                        if xi - 1 >= 0 and grid[yi][xi - 1] == "1":
                            queue.appendleft((yi, xi - 1))

                        if xi + 1 < n and grid[yi][xi + 1] == "1":
                            queue.appendleft((yi, xi + 1))

        return num_islands


# @leet end

