class Solution {
public:
    int uniquePaths(int m, int n) {
        int paths[m][n];
        
        for (int i = 0; i < n; i++) {
            paths[0][i] = 1;
        }
        
        for (int i = 0; i < m; i++) {
            paths[i][0] = 1;
        }
        
        for (int y = 1; y < m; y++) {
            for (int x = 1; x < n; x++) {
                int prevUp = y - 1 >= 0 ? paths[y - 1][x] : 0;
                int prevLeft = x - 1 >= 0 ? paths[y][x-1] : 0;
                
                paths[y][x] = prevUp + prevLeft;
            }
        }
        
        return paths[m-1][n-1];
    }
};