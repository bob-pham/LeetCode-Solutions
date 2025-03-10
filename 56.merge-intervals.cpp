// @leet start
bool comp(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> result;
        vector<int> curr = intervals[0];

        for (int i = 0; i < intervals.size(); i++) {
            vector<int> inter = intervals[i];
            if (curr[0] <= inter[0] && curr[1] >= inter[0]) {
                curr[1] = max(curr[1], inter[1]);
            } else {
                result.push_back(curr);
                curr = inter;
            }
        }

        result.push_back(curr);

        return result;
    }
};
// @leet end
