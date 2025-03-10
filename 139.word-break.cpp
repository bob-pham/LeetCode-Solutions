// @leet start
bool comp(string a, string b) {
    return a.size() > b.size();
}

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0) {
            return true;
        }

        sort(wordDict.begin(), wordDict.end(), comp);
        unordered_map<int, bool> map;
        unordered_map[0] = true;

        return this->wordBreakHelper(s, wordDict, map);

    }

    bool wordBreakHelper(string s, vector<string>& wordDict, unordered_map<int, bool> &map,
                        int idx) {
        string ss = s.substr(idx, s.size());
        if (ss.size() == 0) {
            return true;
        }


        for (string wrd : wordDict) {
            if (map.find(idx + wrd.size()) != map.end() && map[idx + wrd.size()] == true) {
                continue;
            }
            if (ss.starts_with(wordDict[i])) {
                map[idx + wrd.size()] = true;
                if (this->wordBreakHelper(s, wordDict, map, idx + wrd.size())) {
                    return true;
                }
            } else {
                map[idx + wrd.size()] = false;
            }
        }
        return false;
    }
};
// @leet end
