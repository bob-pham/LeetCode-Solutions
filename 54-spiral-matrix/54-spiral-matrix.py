class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        top = 0
        right = len(matrix[0])
        left = 0
        bottom = len(matrix)
        count = bottom * right
        dir = 0
        result = []
        
        while (count > 0): 
            if (dir == 0):                
                temp = matrix[top];
                for i in range(left, right):
                    result.append(temp[i])
                    count -= 1
                top += 1
                dir += 1
                right -= 1
            elif (dir == 1):
                for i in range (top, bottom):              
                    result.append(matrix[i][right])
                    count -= 1
                dir += 1
            elif (dir == 2):
                temp = matrix[bottom - 1]
                for i in range (right - 1, left - 1, -1):
                    result.append(temp[i])
                    count -= 1
                bottom -= 1
                dir += 1
            elif (dir == 3):
                for i in range(bottom - 1, top - 1, -1):     
                    result.append(matrix[i][left])
                    count -= 1
                left += 1
                dir = 0
        return result;
