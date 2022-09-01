class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unsigned long length = INT_MAX;
        string result = "";
        
        for (string str : strs) {
            length = min(length, str.length());
        }
            
        for (int i = 0; i < length; i++) {
            char temp = strs[0][i];
            
            for (string str : strs) {
                if (str[i] != temp)
                    return result;
            }
            
            result += temp;
        }
        
        return result;
    }
};