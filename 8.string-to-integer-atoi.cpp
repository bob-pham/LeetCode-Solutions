// @leet start
class Solution {
public:
    int myAtoi(string s) {
        int64_t result = 0;
        int sign = 1;
        bool sign_change = false;
        bool digit = false;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (0x7FFFFFFF < result) {
                if (sign == 1) {
                    return 0x7FFFFFFF;
                }
                return 0xFFFFFFFF80000000;
            }
            if (!digit && c == ' ') {
                continue;
            } else if (c == '-')  {
                if (i + 1 < s.size() && !(s[i + 1] >= '0' && s[i + 1] <= '9')) {
                    return result * sign;
                }
                if (sign_change || digit) {
                    return result * sign;
                }
                sign = -1;
                sign_change = true;
            } else if (c == '+') {
                if (i + 1 < s.size() && !(s[i + 1] >= '0' && s[i + 1] <= '9')) {
                    return result * sign;
                }
                if (sign_change || digit) {
                    return result * sign;
                }
                sign = 1;
                sign_change = true;
            } else if (!(c >= '0' && c <= '9')) {
                    return result * sign;
            } else {
                digit = true;
                result *= 10;
                result += c - '0';
            }

        }
        if (0x7FFFFFFF < result) {
                if (sign == 1) {
                    return 0x7FFFFFFF;
                }
                return 0xFFFFFFFF80000000;
            }
        
        return result * sign;
    }
};
// @leet end
