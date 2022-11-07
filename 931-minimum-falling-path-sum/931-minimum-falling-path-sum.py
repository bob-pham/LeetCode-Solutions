import sys

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        w = len(matrix[0])
        for i in range(1, len(matrix)):
            for j in range(w):
                x = matrix[i - 1][j - 1] if j - 1 >= 0 else sys.maxsize
                y = matrix[i - 1][j] 
                z  = matrix[i - 1][j + 1] if j + 1 < w else sys.maxsize
                matrix[i][j] += min(x, y, z)
                
        result = sys.maxsize
        for i in range(w):
            result = min(matrix[len(matrix) - 1][i], result)

        return result