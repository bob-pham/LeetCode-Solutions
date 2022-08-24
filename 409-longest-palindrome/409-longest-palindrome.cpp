class Solution {
public:
    int longestPalindrome(string s) {
        
        if (s.length() == 1) {
            return 1;
        }
        
        unordered_map<char, int> letters;
        int odds = 0;
        
        for (char c : s) {
            letters[c]++;
        }

        for (const auto& [key, value] : letters) {
            if (value % 2)
                odds++;
        }
        
        if (odds == 1 || odds == 0) {
            return s.length();
        }
        
        return s.length() - odds + 1;
    }
};