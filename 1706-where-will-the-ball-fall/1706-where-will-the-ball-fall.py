class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        m = len(grid)
        n = len(grid[0])
        result = []
        
        for i in range(n):
            col = i
            row = 0
            
            while (row < m):
                if (grid[row][col] == 1):
                    if (col + 1 >= n or grid[row][col + 1] == -1):
                        col = -1
                        break
                    else: 
                        col += 1
                else:
                    if (col - 1 < 0 or grid[row][col - 1] == 1):
                        col = -1
                        break
                    else:
                        col -= 1
                row += 1
            
            result.append(col)
        
        return result