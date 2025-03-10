// @leet start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int h = board.size();
        int w = board[0].size();

        for (int y = 0; y < h; y++) {
            bool map[9] = {false};
            for (int x = 0; x < w; x++) {
                char c = board[y][x];
                if (c == '.') {
                    continue;
                }
                if (map[c - '1']) {
                    return false;
                }
                map[c-'1'] = true;
            }
        }

        for (int x = 0; x < w; x++) {
            bool map[9] = {false};
            for (int y = 0; y < h; y++) {
                char c = board[y][x];
                if (c == '.') {
                    continue;
                }
                if (map[c - '1']) {
                    return false;
                }
                map[c-'1'] = true;
            }
        }

        for (int y = 0; y < h; y += 3) {
            for (int x = 0; x < w; x+= 3) {
                bool map[9] = {false};
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[y + i][x + j];
                        if (c == '.') {
                            continue;
                        }
                        if (map[c - '1']) {
                            return false;
                        }
                        map[c-'1'] = true;                       
                    }
                }
            }
        }

        return true;
    }
};
// @leet end
