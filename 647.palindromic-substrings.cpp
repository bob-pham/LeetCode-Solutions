// @leet start
class Solution {
public:
    int countSubstrings(string s) {
        int i = 1;
        int s_len = s.size();
        int result = s_len;
        while (i < s_len) {
            int right = i + 1;
            int left = i - 1;

            while(right < s_len && left >= 0 && s[left] == s[right]) {
                result++;
                left--;
                right++;
            }

            left = i - 1;
            right = i + 1;

            if (s[i] == s[left]) {
                result++;
                left--;
                while(right < s_len && left >= 0 && s[left] == s[right]) {
                    result++;
                    left--;
                    right++;
                }
            }
            i++;
        }

        return result;
    }
};
// @leet end
