// @leet start
#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> found;
        for (int i = 0; i < nums.size(); i++) {
             int val = nums[i];
            if (found.find(val) == found.end()) {
                found[val] = i;
            } else {
                if (i - found[nums[i]] <= k) {
                    return true;
                }
                found[val] = i;
            }
        }

        return false;
    }
};
// @leet end
