// @leet start
// [2,4,5,6,7,0,1]
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(right - left >= 2){
            int middle = (right + left) / 2;
            printf("%d %d %d\n", left, middle, right);
            if (nums[left] < nums[middle]) {
                left = middle;
            }

            if (nums[middle] < nums[right]) {
                right = middle;
            }
        }
        
        return min(nums[left], nums[right]);
    }
};
// @leet end
