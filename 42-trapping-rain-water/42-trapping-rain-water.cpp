class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int left[size];
        int right[size];
        int curr_max = 0;
        int water = 0;
        
        for (int i = 0; i < size; i++) {
            curr_max = max(curr_max, height.at(i));
            left[i] = curr_max;
        }
        
        curr_max = 0;
        
        for (int i = size - 1; i >= 0; i--) {
            curr_max = max(curr_max, height.at(i));
            right[i] = curr_max;
        }
        
        for (int i = 0; i < size; i++) {
            water += min(left[i], right[i]) - height.at(i);
        }
        
        return water;
    }
};