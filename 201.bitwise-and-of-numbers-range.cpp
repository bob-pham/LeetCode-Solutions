// @leet start
#include <cstdint>
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // 1000
        // 1110
        if (left == 0 || right == 0) {
            return 0;
        }

        if (right - left <= 1) {
            return right & left;
        }

        uint32_t temp = left ^ right;
        int diff_index = 0;
        while (temp > 0) {
            diff_index++;
            temp >>= 1;
        }

        uint32_t mask = ~((1 << diff_index-1) - 1);
        return left & mask;
    }
};
// @leet end
