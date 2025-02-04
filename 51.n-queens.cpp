// @leet start
class Solution {
public:
    vector<string> createEmptyBoard(int n) {
        vector<string> result;
        string str = "";

        for (int i = 0; i < n; i++) {
            str += ".";
        }

        for (int i = 0; i < n; i++) {
            result.push_back(str);
        }

        return result;
    }

    bool isValid(const vector<string> &board, int n, int x, int y) {
        for (int i = 0; i < n; i++) {
            if (board[y][i] == 'Q') {
                return false;
            }

            if (board[i][x] == 'Q') {
                return false;
            }
        }

        int i = x;
        int j = y;

        while (i < n && j < n) {
            if (board[j][i] == 'Q') {
                return false;
            }
            i++;
            j++;
        }

        i = x;
        j = y;
        while (i >= 0 && j < n) {
            if (board[j][i] == 'Q') {
                return false;
            }
            i--;
            j++;
        }

        i = x;
        j = y;
        while (i < n && j >= 0) {
            if (board[j][i] == 'Q') {
                return false;
            }
            i++;
            j--;
        }

        i = x;
        j = y;
        while (i >= 0 && j >= 0) {
            if (board[j][i] == 'Q') {
                return false;
            }
            i--;
            j--;
        }

        return true;
    }

    void dfs(vector<string> &board, int size, int start_x, int start_y, int left, vector<vector<string>> &result) {
        for (int y = start_y; y < size; y++) {
            for (int x = start_x; x < size; x++) {
                if (isValid(board, size, x, y)) {
                    if (left - 1 == 0) {
                        board[y][x] = 'Q';
                        vector<string> temp = board;
                        result.push_back(temp);
                        board[y][x] = '.';
                        continue;
                    }
                    board[y][x] = 'Q';
                    dfs(board, size, x, y, left - 1, result);
                    board[y][x] = '.';
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> curr = createEmptyBoard(n);
        dfs(curr, n, 0, 0, n, result);
        return result;
    }
};
// @leet end
