// @leet start
#include <queue>
#include <utility>

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        int num_islands = 0;

        queue<pair<int, int>> todo;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (grid[y][x] == '1') {
                    num_islands++;
                    todo.push(pair<int,int>(y, x));

                    while(todo.size() > 0) {
                        pair<int, int> curr = todo.front();
                        todo.pop();

                        int ly = curr.first;
                        int lx = curr.second;

                        if (grid[ly][lx] == '0') {
                            continue;
                        }

                        grid[ly][lx] = '0';

                        if (ly + 1 < height) {
                            todo.push(pair<int, int>(ly + 1, lx));
                        }

                        if (ly - 1 >= 0) {
                            todo.push(pair<int, int>(ly - 1, lx));
                        }

                        if (lx + 1 < width) {
                            todo.push(pair<int, int>(ly, lx + 1));
                        }

                        if (lx - 1 >= 0) {
                            todo.push(pair<int, int>(ly, lx - 1));
                        }
                    }
                }
            }
        }

        return num_islands;
        
    }
};
// @leet end
