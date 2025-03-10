// @leet start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());

            if (map.find(key) == map.end()) {
                map[key] = vector<string>();
            }

            map[key].push_back(s);
        }

        vector<vector<string>> result;

        for (const auto& s : map) {
            result.push_back(s.second);
        }

        return result;
        
    }
};
// @leet end
