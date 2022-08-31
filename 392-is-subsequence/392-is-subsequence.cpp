class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int tLength = t.length();
        int sLength = s.length();
        int pos = 0;
        
        if (sLength > tLength) {
            return false;
        }
        
        if (sLength == tLength) {
            return s == t;
        }
            
        for (char c : t) {
            if (pos >= sLength) {
                return true;
            }
            
            if (c == s[pos]) {
                pos++;
            }
        }
            
        return pos == sLength;
        
    }
};