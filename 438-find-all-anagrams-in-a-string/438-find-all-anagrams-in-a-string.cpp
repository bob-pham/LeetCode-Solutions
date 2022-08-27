class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        unordered_map<char, int> pLetters;
        unordered_map<char, int> sLetters;
        vector<int> result;
        
        for (char c : p) {
            pLetters[c]++;
        }
        
        for (int i = 0; i < p.length(); i++) {
            sLetters[s[i]]++;
        }
        
        if (isSame(pLetters, sLetters)) {
            result.push_back(0);
        }
        
        for (int i = p.length(); i < s.length(); i++) {
            int back = i - p.length();
            
            sLetters[s[back]]--;
            sLetters[s[i]]++;                        
            
            if (isSame(pLetters, sLetters)) {
                result.push_back(back + 1);
            }
            
        }
        
        return result;
        
    }
    
    bool isSame(unordered_map<char, int> x, unordered_map<char,int> y) {        
        for (auto const key : x) {
            if (y[key.first] != key.second) {
                return false;
            }
        }
        return true;
    }
    
};