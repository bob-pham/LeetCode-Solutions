// @leet start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        make_heap(nums.begin(), nums.end());
        int count = 1;
        pop_heap(nums.begin(), nums.end());
        int prev = nums.back();
        nums.pop_back();

        while(nums.size() > 0) {
            pop_heap(nums.begin(), nums.end());
            if (count == 3) {
                count = 1;
                prev = nums.back();
            } else {
                if (nums.back() != prev) {
                    return prev;
                }
                count++;
            }
            nums.pop_back();

        }

        return prev;
    }
};
// @leet end
