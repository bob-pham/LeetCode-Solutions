// @leet start
#include <algorithm>
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        vector<int> to_use;
        int a;

        std::make_heap(nums1.begin(), nums1.end(), greater<int>{});
        std::make_heap(nums2.begin(), nums2.end(), greater<int>{});

        for (int i = 0; i < k; i++) {
            std::pop_heap(nums2.begin(), nums2.end(), greater<int>{});
            std::pop_heap(nums1.begin(), nums1.end(), greater<int>{});
            result.push_back({nums1.back(), nums2.back()});

            int a = nums1.back();
            int b = nums2.back();
            nums1.pop_back();
            nums2.pop_back();

            if (nums1.front() + b < nums2.front() + a) {
                nums2.push_back(b);
                std::push_heap(nums2.begin(), nums2.end(), greater<int>{});
            } else {
                nums1.push_back(a);
                std::push_heap(nums1.begin(), nums1.end(), greater<int>{});
            }

        }

        return result;
    }
};
// @leet end
