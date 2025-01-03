# @leet start
class Solution:

    def createBoard(self, n):
        return ["." * n for _ in range(n)]
    
    def is_valid_pos(self, x, y, board):
        n = len(board)
        x_count, y_count = 0, 0
        for i in range(n):
            if board[y][i] == "Q":
                x_count += 1
                if x_count > 1:
                    return False

        for i in range(n):
            if board[i][x] == "Q":
                y_count += 1
                if y_count > 1:
                    return False

        return x_count <= 1 and y_count <= 1

    def solveNQueens(self, n: int) -> List[List[str]]:
        result = []

        def dfs(curr_n, board):



        return result
        
# @leet end
