// @leet start
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int i = 1;
        int result = 0;
        while (i < colors.size()) {
            int len = 2;
            while (i < colors.size() && len < k) {
                if (colors[i-1] != colors[i]) {
                    len++;
                } else {
                    break;
                }
                i++;
            }

            if (len < k) {
                i++;
                continue;
            }

            while (i < colors.size() && colors[i] != colors[i-1]) {
                cout << i << endl;
                i++;
                result++;
            }
        }
        return result;
    }
};
// @leet end
