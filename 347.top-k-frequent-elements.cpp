// @leet start
#include <unordered_map>

bool comp(pair<int, int> a, pair<int,int> b) {
    return a.second < b.second;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;

        for (int num : nums) {
            map[num]++;
        }

        vector<pair<int, int>> list;
        for (const auto &p : map) {
            list.push_back(p);
        }

        make_heap(list.begin(), list.end(), comp);
        vector<int> result;

        for (int i = 0; i < k; i++) {
            pop_heap(list.begin(), list.end(), comp);
            result.push_back(list.back().first);
            list.pop_back();
        }

        return result;
    }
};
// @leet end
