// @leet start
class Solution {
    public boolean checkXMatrix(int[][] grid) {
        // check first diagonal
        int n = grid.length;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (x == y || (n-y-1) == x) {
                    if (grid[y][x] == 0) {
                        return false;
                    }
                } else if (grid[y][x] != 0) {
                    return false;
                }
            }
        }
       return true; 
    }
}
// @leet end
