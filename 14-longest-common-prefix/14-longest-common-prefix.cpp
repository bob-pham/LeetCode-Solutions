class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int count = 0;
        
        while (true) {
            if (count >= strs[0].length()) {
                return result;
            }
            
            char curr = strs[0][count];
            
            for (string str : strs) {
                if (str.length() < count || str[count] != curr)
                    return result;
            }
            
            result += curr;
            count++;            
        }
        
        return result;
    }
};