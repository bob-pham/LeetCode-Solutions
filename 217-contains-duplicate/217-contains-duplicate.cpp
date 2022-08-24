class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int, int> counts;
        
        for (int i : nums) {
            if (++counts[i] > 1)
                return true;
        }
        
        return false;
    }
};