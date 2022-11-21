class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = 0;
        int max2 = 0;
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for (int i : nums) {
            if (i > max1) {
                max2 = max1;
                max1 = i;
            } else if (i > max2) {
                max2 = i;
            } 
            
            if (i < min1) {
                min2 = min1;
                min1 = i;
            } else if (i < min2) {
                min2 = i;
            }
        }
       return (max1 * max2) - (min1 * min2);
    }
};