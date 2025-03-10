// @leet start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (k % len == 0) {
            return;
        }

        int idx = k % len;
        for (int i = 0; i < len / 2; i++) {
            int temp = nums[i];
            nums[i] = nums[len - i - 1];
            nums[len - i - 1] = temp;
        }

        int mid = ((len - idx)  / 2) + idx;

        cout << mid << endl;

        for (int i = idx; i < mid; i++) {
            int temp = nums[i];
            nums[i] = nums[len - (i-idx) - 1];
            nums[len - (i-idx) - 1] = temp;
        }

        for (int i = 0; i < idx / 2; i++) {
            int temp = nums[i];
            nums[i] = nums[idx - i - 1];
            nums[idx - i - 1] = temp;
        }
    }
};
// @leet end
