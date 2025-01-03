# @leet start
from collections import deque 

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        max_size = 0

        for y in range(m):
            for x in range(n):
                if grid[y][x] == 1:
                    curr_size = 0
                    todo = deque()
                    todo.append((x,y))

                    while len(todo) > 0:
                        xx, yy = todo.popleft()

                        if grid[yy][xx] == 0:
                            continue
                        
                        grid[yy][xx] = 0
                        curr_size += 1

                        if xx - 1 >= 0:
                            todo.append((xx - 1, yy))

                        if xx + 1 < n:
                            todo.append((xx + 1, yy))

                        if yy - 1 >= 0:
                            todo.append((xx, yy - 1))

                        if yy + 1 < m:
                            todo.append((xx, yy + 1))

                    max_size = max(max_size, curr_size)
        return max_size
        
# @leet end
