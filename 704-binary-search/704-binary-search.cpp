class Solution {
public:
    int search(vector<int>& nums, int target) {
     
        int back = 0;
        int front = nums.size() - 1;
        
        while (front >= back) {
            int middle = back + (front - back) / 2;
            int curr = nums[middle];
                        
            if (curr == target) {
                return middle;
            } else if (curr > target) {
                front = middle - 1;
            } else {
                back = middle + 1;
            }
        }
        
        return -1;
        
    }
};