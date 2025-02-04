// @leet start
#include <algorithm>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::make_heap(nums.begin(), nums.end(), greater<int>{});

        while(nums.size() > k) {
            std::pop_heap(nums.begin(), nums.end(), greater<int>{});
            nums.pop_back();
        }

        return nums.front();
    }
};
// @leet end
