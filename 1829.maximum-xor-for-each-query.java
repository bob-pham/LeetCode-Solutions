// @leet start
class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int maxNumMask = (1 << maximumBit) - 1;
        int[] result = new int[nums.length];
        int xorRes = nums[0];
        for (int i = 1; i < nums.length; i++) {
            xorRes = xorRes ^ nums[i];
        }

        int o = ~xorRes;
        o = o & ~(1 << 31);
        o = o & maxNumMask;
        result[0] = o;
        for (int maxIndex = nums.length - 1; maxIndex > 0; maxIndex--) {
            xorRes = xorRes ^ nums[maxIndex];
            int opp = ~xorRes;
            opp = opp & ~(1 << 31);
            opp = opp & maxNumMask;
            result[nums.length - maxIndex] = opp;
        }
        
        return result;
    }
}
// @leet end
