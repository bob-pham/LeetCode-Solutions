class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int last = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (last != nums[i]) {
                nums[k++] = nums[i];
                last = nums[i];
            }
            
        }
        
        return k;
    }
};