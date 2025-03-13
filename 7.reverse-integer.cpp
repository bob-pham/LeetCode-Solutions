// @leet start
class Solution {
public:
    int reverse(int x) {
        int neg = false;
        int64_t result = 0;

        if (x == -2147483648) {
            return 0;
        }

        if (x < 0) {
            neg = true;
            x *= -1;
        }
        int digits = 0;
        int temp = x;
        while (temp > 0) {
            digits++;
            temp /= 10;
        }

        temp = x;

        while (temp > 0) {
            uint64_t num = temp % 10;

            for (int i = 1; i < digits; i++) {
                num *= 10;
            }

            result += num;
            digits--;
            temp /= 10;
            
            if (neg && result > 2147483648) {
                return 0;
            }
            if (!neg && result > 0x7FFFFFFF) {
                return 0;
            }
        }
        
        return neg ? -result : result;
    }
};
// @leet end
