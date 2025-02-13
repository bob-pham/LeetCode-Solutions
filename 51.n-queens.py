# @leet start
class Solution:

    def createBoard(self, n):
        return ["." * n for _ in range(n)]
    
    def cloneBoard(self, board):
        result = []
        for b in board:
            result.append([i for i in b])
        return result
    
    def is_valid_pos(self, x, y, board):
        n = len(board)
        for i in range(n):
            if i == x:
                continue
            if board[y][i] == "Q":
                return False

        for i in range(n):
            if i == y:
                continue
            if board[i][x] == "Q":
                return False

        i = x + 1
        j = y + 1
        while i < n and j < n:
            if board[j][i] == "Q":
                return False

        i = x - 1
        j = y + 1
        while i < n and j < n:
            if board[j][i] == "Q":
                return False

        i = x - 1
        j = y - 1
        while i < n and j < n:
            if board[j][i] == "Q":
                return False

        i = x + 1
        j = y - 1
        while i < n and j < n:
            if board[j][i] == "Q":
                return False
        
        return True

    def solveNQueens(self, n: int) -> List[List[str]]:
        result = []
        curr_board = self.createBoard(n)

        def dfs(curr_n, board, y_start):
            if curr_n <= 0:
                result.append(self.cloneBoard(board))

            for y in range(y_start, n):
                for x in range(n):
                    if board[y][x] == '.':
                        s_val = board[y]
                        s_new = s_val[:x] + "Q" + s_val[x+1:]
                        board[y] = s_new
                        dfs(curr_n - 1, board, y)
                        board[y] = s_val

        dfs(n, curr_board, 0)

        return result
        
# @leet end
