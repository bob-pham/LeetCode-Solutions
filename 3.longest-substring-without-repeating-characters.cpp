// @leet start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if (len <= 1) {
            return len;
        }

        unordered_set<char> chars;
        int back = 0;
        int result = 1;
        int curr = 1;
        chars.insert(s[0]);

        for (int i = 1; i < len; i++) {
            while(chars.find(s[i]) != chars.end()) {
                chars.erase(s[back]);
                back++;
                curr--;
            }
            chars.insert(s[i]);
            curr++;
            result = max(result, curr);
        }
        return result;
        
    }
};
// @leet end
