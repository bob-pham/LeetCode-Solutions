class Solution {
public:
    int characterReplacement(string s, int k) {
     
        unordered_map<char, int> letters;
        int backpointer = 0;
        int maxChar = 0;
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            maxChar = max(maxChar, ++letters[s[i]]);
            if (i - backpointer >= k + maxChar) {
                letters[s[backpointer++]]--;
            } else {
                result++;
            }
            
        }
        return result;
        
    }
};