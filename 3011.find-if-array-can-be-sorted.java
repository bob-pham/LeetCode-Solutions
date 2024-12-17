// @leet start
class Solution {
    public boolean canSortArray(int[] nums) {
        boolean madeChange = true;
        while (madeChange) {
            madeChange = false;
            for (int i = 1; i < nums.length; i++) {
                if (nums[i] < nums[i-1] && Integer.bitCount(nums[i]) == Integer.bitCount(nums[i-1])) {
                    int temp = nums[i];
                    nums[i] = nums[i-1];
                    nums[i-1] = temp;
                    madeChange = true;
                }
            }
        }

        // check sorted
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < nums[i-1]) {
                return false;
            }
        }
       
        return true;
    }
}
// @leet end
