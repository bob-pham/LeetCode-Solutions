class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            int col = i;
            int row = 0;
            
            while (row < m) {
                if (grid[row][col] == 1) {
                    if (col + 1 >= n || grid[row][col + 1] == -1) {
                        col = -1;
                        break;
                    } else {
                        col++;
                    }
                } else {
                    if (col - 1 < 0 || grid[row][col - 1] == 1) {
                        col = -1;
                        break;
                    } else {
                        col--;
                    }
                }
                row++;
            }          
            
            result.push_back(col);
        }
        
        return result;
    }
};