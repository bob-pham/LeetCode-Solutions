// @leet start
class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int result = 0;
        int numCount = 0;


        for (int i : nums) {
            if (i == 1 && numCount < goal) {
                numCount++;
            } else {
                result++;
            }
        }
        
        return result;
    }
}
// @leet end
