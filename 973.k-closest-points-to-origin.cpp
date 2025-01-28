// @leet start

bool compare(const vector<int> &a, const vector<int> &b) {
        int dist1 = (a[0] * a[0]) + (a[1] * a[1]);
        int dist2 = (b[0] * b[0]) + (b[1] * b[1]);

        return dist1 < dist2;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::make_heap(points.begin(), points.end(), compare);

        while (points.size() > k) {
            std::pop_heap(points.begin(), points.end(), compare);
            points.pop_back();
        }
        
        return points;
    }
};
// @leet end
