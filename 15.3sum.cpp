// @leet start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        unordered_map<int, vector<int>> map;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (map.find(num) == map.end()) {
                map[num] = vector<int>();
            }
            map[num].push_back(i);
        }

        for (int num : nums) {
            unordered_set<int> visited;
            int k = -num;
            vector<int> &e1 = map[num];

            for (int inner : nums) {
                int target = abs(inner - k);
                if (visited.find(inner) != visited.end() ||
                    visited.find(target) != visited.end()) {
                    continue;
                }
                if (map.find(target) != map.end()) {
                    visited.insert(inner);
                    visited.insert(target);

                    for (int a : e1) {
                        for (int b : map[inner]) {
                            for (int c : map[target]) {
                                if (a != b && b != c && a != c) {
                                    result.push_back(vector<int>({num, inner, target}));
                                    break;
                                }
                            }
                        }
                    }

                }
            }
        }
        return result;
    }
};
// @leet end
