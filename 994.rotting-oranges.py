# @leet start

from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        minutes = 0
        todo = deque()
        next_todo = deque()

        m, n = len(grid), len(grid[0])

        for y in range(m):
            for x in range(n):
                if grid[y][x] == 2:
                    todo.append((y, x))

        while len(todo) > 0 or len(next_todo) > 0:
            while len(todo) > 0:
                y, x = todo.popleft()
                if grid[y][x] == 2:
                    continue

                grid[y][x] = 2

                if y + 1 < m and grid[y+1][x] == 1:
                    next_todo.append((y+1, x))

                if y - 1 >= 0 and grid[y-1][x] == 1:
                    next_todo.append((y-1, x))

                if x + 1 < n and grid[y][x+1] == 1:
                    next_todo.append((y, x+1))

                if x - 1 >= 0 and grid[y][x-1] == 1:
                    next_todo.append((y, x-1))

            minutes += 1
            todo = next_todo
            next_todo = deque

        return minutes
        
# @leet end
