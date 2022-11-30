class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counts;
        set<int> occurances;
        
        for (int i : arr) {
            counts[i]++;
        }
        
        for (const auto i : counts) {
            if (occurances.find(i.second) == occurances.end()) {
                occurances.insert(i.second);
            } else {
                return false;
            }
        }
        
        return true;
    }
};