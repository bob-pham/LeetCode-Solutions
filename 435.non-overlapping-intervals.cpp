// @leet start
bool compare(const vector<int> &a, vector<int> &b) {
    if (a[1] != b[1]) {
        return a[1] < b[1];
    } else {
        return a[0] < b[0];
    }
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        sort(intervals.begin(), intervals.end(), compare);

        int int_right = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int c_right = intervals[i][1];
            int c_left = intervals[i][0];

            if (int_right > c_left) {
                result++;
            } else {
                int_right = c_right;
            }


        }

        return result;
    }
};
// @leet end
