class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ransom;
        unordered_map<char, int> mag;
        
        for (char c : ransomNote) {
            ransom[c]++;
        }
        
        for (char c : magazine) {
            mag[c]++;
        }
        
        for (const auto key : ransom) {
            if (!mag[key.first] || mag[key.first] < key.second) {
                return false;
            } 
        }
        
        return true;
    }
};