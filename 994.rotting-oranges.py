# @leet start
from collections import deque
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        memo = [[sys.maxsize for _ in range(m)] for _ in range(n)]

        for y in range(n):
            for x in range(m):
                cell_type = grid[y][x]
                if cell_type == 2:
                    visited = [[False for _ in range(m)] for _ in range(n)]
                    todo = deque()

                    if x - 1 >= 0:
                        todo.append((x-1, y, 1))
                    if x + 1 < m:
                        todo.append((x+1, y, 1))
                    if y - 1 >= 0:
                        todo.append((x, y-1, 1))
                    if y + 1 < n:
                        todo.append((x, y+1, 1))

                    while len(todo) > 0:
                        xx, yy, dist = todo.popleft()
                        if visited[yy][xx]:
                            continue
                        if grid[yy][xx] != 1:
                            continue

                        visited[yy][xx] = True
                        memo[yy][xx] = min(memo[yy][xx], dist)

                        if xx - 1 >= 0:
                            todo.append((xx-1, yy, dist + 1))
                        if xx + 1 < m:
                            todo.append((xx+1, yy, dist + 1))
                        if yy - 1 >= 0:
                            todo.append((xx, yy-1, dist + 1))
                        if yy + 1 < n:
                            todo.append((xx, yy+1, dist + 1))
        global_max = 0
        for y in range(n):
            for x in range(m):
                if grid[y][x] == 1:
                    if memo[y][x] == sys.maxsize:
                        return -1
                    else:
                        global_max = max(global_max, memo[y][x])

        return global_max

        
# @leet end
