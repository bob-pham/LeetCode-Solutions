// @leet start
class Solution {
    public int minimumOperations(int[] nums) {
        int result = 0;
        int min = this.getMinNonZero(nums);

        while (min != -1) {
            result++;

            for (int i = 0; i < nums.length; i++) {
                if (nums[i] == 0) {
                    continue;
                }
                nums[i] -= min;
            }

            min = this.getMinNonZero(nums);
        }

        return result;
    }

    private int getMinNonZero(int[] nums) {
        int min = Integer.MAX_VALUE;
        for (int i : nums) {
            if (i == 0) {
                continue;
            }
            min = Math.min(i, min);
        }
        if (min == Integer.MAX_VALUE) {
            return -1;
        }
        return min;
    }
}
// @leet end
