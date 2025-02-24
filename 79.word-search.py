# @leet start
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        wl = len(word)
        visited = [[False for _ in range(n)] for _ in range(m)]

        def dfs(y, x, idx):
            if idx >= wl:
                return True

            if visited[y][x] or board[y][x] != word[idx]:
                return False

            visited[y][x] = True
            idx += 1
            if idx >= wl:
                return True

            if y + 1 < m and dfs(y + 1, x, idx):
                return True

            if y - 1 >= 0 and dfs(y - 1, x, idx):
                return True

            if x + 1 < n and dfs(y, x + 1, idx):
                return True

            if x - 1 >= 0 and dfs(y, x - 1, idx):
                return True

            visited[y][x] = False

            return False


        for y in range(m):
            for x in range(n):
                if dfs(y, x, 0):
                    return True

        return False

        
# @leet end
