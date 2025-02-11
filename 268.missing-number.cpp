// @leet start
#include <algorithm>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> d_nums;

        for (int i : nums) {
            d_nums.insert(i);
        }

        for (int i = 0; i <= n; i++) {
            if (d_nums.find(i) == d_nums.end()) {
                return i;
            }
        }

        return -1;
    }
};
// @leet end
