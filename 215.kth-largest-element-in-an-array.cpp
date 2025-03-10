// @leet start
bool comp (int a, int b) {
    return a > b;
}
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        std::make_heap(nums.begin(), nums.end(), comp);
        int idx = nums.size() - k;

        for (int i = 0; i < idx; i++) {
            std::pop_heap(nums.begin(), nums.end(), comp);
            nums.pop_back();
        }


        std::pop_heap(nums.begin(), nums.end(), comp);
        return nums.back();
    }
};
// @leet end
