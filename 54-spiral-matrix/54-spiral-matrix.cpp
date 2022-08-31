class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int right = matrix[0].size();
        int left = 0;
        int bottom = matrix.size();
        int count = bottom * right;
        int dir = 0;
        vector<int> result;
        
        while (count > 0) {
            if (dir == 0) {                
                for (int i = left; i < right; i++) {
                    vector<int> temp = matrix[top];
                    result.push_back(temp[i]);
                    count--;
                }
                top++;
                dir++;
                right--;
            } else if (dir == 1) {
                for (int i = top; i < bottom; i++) {              
                    result.push_back(matrix[i][right]);
                    count--;   
                }
                dir++;
            } else if (dir == 2) {
                
                vector<int> temp = matrix[bottom - 1];
                for (int i = right - 1; i >= left; i--) {
                    result.push_back(temp[i]);
                    count--;
                }
                bottom--;
                dir++;
            } else if (dir == 3) {
                for (int i = bottom - 1; i >= top; i--) {    
                    result.push_back(matrix[i][left]);
                    count--;
                }
                left++;
                dir = 0;
            }
        }
        return result;
    }
};