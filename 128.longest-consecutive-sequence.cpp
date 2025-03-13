// @leet start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> map;
        for (int num: nums) {
            map[num] = 1;
        }

        for (int num: nums) {
            result = max(result, longestHelper(num, map));
        }


        return result;
    }

    int longestHelper(int num, unordered_map<int,int> &map) {
        if (map.find(num) == map.end()) {
            return 0;
        }

        if (map[num] == 1) {
            map[num] = longestHelper(num + 1, map) + 1;
        }

        return map[num];
    }
};
// @leet end
