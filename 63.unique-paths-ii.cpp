// @leet start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[m - 1][n - 1] == 1) {
             return 0;
        }
        if (obstacleGrid[0][0] == 1) {
             return 0;
        }
        
        bool no_obstacle = true;
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                obstacleGrid[i][0] = -1;
                no_obstacle = false;
            } else if (no_obstacle) {
                obstacleGrid[i][0] = 1;
            }
        }

        no_obstacle = true;
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 1) {
                obstacleGrid[0][i] = -1;
                no_obstacle = false;
            } else if (no_obstacle) {
                obstacleGrid[0][i] = 1;
            }
        }

        obstacleGrid[0][0] = 1;

        for (int y = 1; y < m; y++) {
            for (int x = 1; x < n; x++) {
                if (obstacleGrid[y][x] == 1) {
                    obstacleGrid[y][x] = -1;
                } else {
                    int top = 0;
                    int left = 0;

                    if (y - 1 >= 0) {
                        top = max(top, obstacleGrid[y-1][x]);
                    }

                    if (x - 1 >= 0) {
                        left = max(left, obstacleGrid[y][x-1]);
                    }

                    obstacleGrid[y][x] = top + left;
                }
            }
        }
        
        return obstacleGrid[m - 1][n - 1];
    }
};
// @leet end
