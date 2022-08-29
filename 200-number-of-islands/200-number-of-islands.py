class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        m = len(grid)
        n = len(grid[0])
        islands = 0
        
        for y0 in range(m):
            for x0 in range(n):
                if (grid[y0][x0] == '1'):
                    queue = deque()
                    queue.append([y0,x0])
                    
                    islands += 1
                    
                    while (queue):
                        curr = queue.popleft()
                        y = curr[0]
                        x = curr[1]
                        
                        if (grid[y][x] == '1'):
                            grid[y][x] = '0'
                            
                            if (y + 1 < m and grid[y + 1][x] == '1'):
                                queue.append([y + 1, x])
                            
                            if (y - 1 >= 0 and grid[y - 1][x] == '1'):
                                queue.append([y - 1, x])
                            
                            if (x + 1 < n and grid[y][x + 1] == '1'):
                                queue.append([y, x + 1])
                            
                            if (x - 1 >= 0 and grid[y][x - 1] == '1'):
                                queue.append([y, x - 1])
        
        return islands