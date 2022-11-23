class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
     
        int visited[9];
        bool valid = true;
        
        fill_n(visited, 9, 0);
        
        // Check rows
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (visited[int(board[i][j]) - 49] == 0) {
                        visited[int(board[i][j]) - 49] = 1;
                    } else {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid) {
                break;
            }
            fill_n(visited, 9, 0);
        }
        
        if (!valid) {
            return false;
        }
        

       // Check columns
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (visited[int(board[j][i]) - 49] == 0) {
                        visited[int(board[j][i]) - 49] = 1;
                    } else {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid) {
                break;
            }
            fill_n(visited, 9, 0);
        }
        
        if (!valid) {
            return false;
        }

        
        for (int x = 0; x < 9; x += 3) {
            for (int y = 0; y < 9; y += 3) {
                for (int i = x; i < x + 3; i++) {
                    for (int j = y; j < y + 3; j++) {
                        if (board[j][i] != '.') {
                            if (visited[int(board[j][i]) - 49] == 0) {
                                visited[int(board[j][i]) - 49] = 1;
                            } else {
                                valid = false;
                                break;
                            }
                        }
                    }
                    if (!valid) {
                        break;
                    }
                }
                if (!valid) {
                    break;
                }
                fill_n(visited, 9, 0);
            }
            
            if (!valid) {
                break;
            }
            fill_n(visited, 9, 0);
        }
        
        return valid;
    }
};