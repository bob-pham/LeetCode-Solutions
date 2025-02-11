// @leet start
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        vector<int> left;
        vector<int> right;
        int curr_max = 0;
        
        for (int i = 0; i < height.size(); i++) {
            curr_max = max(height[i], curr_max);
            left.push_back(curr_max);
            right.push_back(0);
        }

        curr_max = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            curr_max = max(height[i], curr_max);
            right[i] = curr_max;
        }

        for (int i = 0; i < height.size(); i++) {
            result += max(min(left[i], right[i]) - height[i], 0);
        }

        return result;
    }
};
// @leet end
