// @leet start
class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int column) {
        int map[10];
        int height = board.size();
        int width = board[0].size();

        for (int i = 0; i < 10; i++) {
            map[i] = 0;
        }

        for (int x = 0; x < width; x++) {
            int idx = board[row][x];
            if (idx == '.') {
                continue;
            }
            idx -= '1';
            if (map[idx] != 0) {
                return false;
            } else {
                map[idx] = 1;
            }
        }

        for (int i = 0; i < 10; i++) {
            map[i] = 0;
        }

        for (int y = 0; y < height; y++) {
            int idx = board[y][column];
            if (idx == '.') {
                continue;
            }
            idx -= '1';
            if (map[idx] != 0) {
                return false;
            } else {
                map[idx] = 1;
            }
        }
        
        for (int i = 0; i < 10; i++) {
            map[i] = 0;
        }

        while (row % 3 != 0) {
            row--;
        }

        while (column % 3 != 0) {
            column--;
        }

        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                int idx = board[row + y][column + x];
                if (idx == '.') {
                    continue;
                }
                idx -= '1';
                if (map[idx] != 0) {
                    return false;
                } else {
                    map[idx] = 1;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>> &board) {
        vector<vector<char>> result;
        int height = board.size();
        int width = board[0].size();

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (board[y][x] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        board[y][x] = c;
                        if (isValid(board, y, x) && solve(board)) {
                            return true;
                        }
                        board[y][x] = '.';
                    }
                return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
// @leet end
