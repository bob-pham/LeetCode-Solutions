class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        vector<char> letters;
        letters.push_back(s[0]);
        
        for (int i = 1; i < s.length(); i++) {
            if (!letters.empty() && letters.back() == s[i]) {
                letters.pop_back();
            } else {
                letters.push_back(s[i]);
            }
        }
        
        for (int i = 0; i < letters.size(); i++) {
            result += letters[i];
        }
        return result;
    }
};