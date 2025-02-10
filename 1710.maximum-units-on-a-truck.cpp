// @leet start

#include <algorithm>
bool compare(const vector<int> &a, const vector<int> &b) {
    return a[1] <= b[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int result = 0;
        std::make_heap(boxTypes.begin(), boxTypes.end(), compare);

        while (truckSize > 0 && !boxTypes.empty()) {
            vector<int> &top = boxTypes.front();
            int box_remove = min(truckSize, top[0]);
            result += top[1] * box_remove;
            top[0] -= box_remove;
            if (top[0] <= 0) {
                std::pop_heap(boxTypes.begin(), boxTypes.end(), compare);
                boxTypes.pop_back();
            }
            truckSize -= box_remove;
            std::make_heap(boxTypes.begin(), boxTypes.end(), compare);
        }
        
        return result;
    }
};
// @leet end
