class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int, int> counts;
        int pos = 0;
        
        for (int i : nums) {
            counts[i]++;
        }
        
        for (auto key : counts) {
            int curr = key.first;
            
            for (int i = 0; i < key.second; i++) {
                nums[pos++] = curr;
            }            
        }
        
        return nums;
    }
};