// @leet start
class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int result = 0;
        int currSum = 0;

        for (int i = 0; i < k; i++) {
            currSum += arr[i];
        }

        if (currSum / k >= threshold) {
            result++;
        }

        for (int i = k; i < arr.length; i++) {
            currSum -= arr[i-k];
            currSum += arr[i];
            if (currSum / k >= threshold) {
                result++;
            }
        }

        return result;
    }
}
// @leet end
