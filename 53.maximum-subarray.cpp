// @leet start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int curr_sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (curr_sum < 0) {
                curr_sum = max(curr_sum, nums[i]);
            } else {
                curr_sum += nums[i];
            }
            max_sum = max(curr_sum, max_sum);
        }
        
        return max_sum;
    }
};
// @leet end
