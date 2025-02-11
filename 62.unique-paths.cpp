// @leet start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> map;

        for (int y = 0; y < m; y++) {
            vector<int> curr_vec;
            for (int x = 0; x < n; x++) {
                curr_vec.push_back(0);
            }
            map.push_back(curr_vec);
        }

        for (int x = 0; x < n; x++) {
            map[0][x] = 1;
        }

        for (int y = 0; y < m; y++) {
            map[y][0] = 1;
        }

        for (int y = 1; y < m; y++) {
            for (int x = 1; x < n; x++) {
                int top = map[y-1][x];
                int left = map[y][x-1];

                map[y][x] = top + left;
            }
        }
        return map[m - 1][n - 1];
    }
};
// @leet end
