class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;        
        int big = 0;
        
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        big = sum;
        
        for (int i = k, j = 0; i < nums.size(); i++, j++) {            
            sum += nums[i];
            sum -= nums[j];
            
            big = max(big, sum);
        }
        return (double) big / k; 
    }
};