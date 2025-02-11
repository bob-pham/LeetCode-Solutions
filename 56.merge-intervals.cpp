// @leet start

#include <algorithm>
bool compare(const vector<int> &a, const vector<int> &b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    } else {
        return a[0] < b[0];
    }
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        std::sort(intervals.begin(), intervals.end(), compare);

        vector<int> prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (prev[1] >= intervals[i][0]) {
                prev[1] = max(intervals[i][1], prev[1]);
                continue;
            }
            result.push_back(prev);
            prev = intervals[i];
        }

        result.push_back(prev);
        
        return result;
    }
};
// @leet end
