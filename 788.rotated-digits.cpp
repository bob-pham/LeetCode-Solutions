// @leet start
#include <unordered_map>
class Solution {
    bool can_rotate(int i) {
        return !(i == 3 || i == 4 || i == 7);
    }
public:
    int rotatedDigits(int n) {
        int result = 0;
        std::unordered_map<int, int> memo;

        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 5;
        memo[3] = -1;
        memo[4] = -1;
        memo[5] = 2;
        memo[6] = 9;
        memo[7] = -1;
        memo[8] = 8;
        memo[9] = 6;

        if (n < 10) {
            for (int i = 0; i <= n; i++) {
                if (can_rotate(i) && memo[i] != i) {
                    result++;
                }
            }
            return result;
        }

        result = 4;

        for (int i = 10; i <= n; i++) {
            int lower = i % 10;
            if (!can_rotate(lower)) {
                memo[i] = -1;
                continue;
            }
            int base = memo[i / 10];
            if (base == -1) {
                memo[i] = -1;
                continue;
            }

            int new_num = (base * 10) + memo[lower];
            if (new_num != i) {
                result++;
            }
            memo[i] = new_num;
        }

        return result;
    }
};
// @leet end
