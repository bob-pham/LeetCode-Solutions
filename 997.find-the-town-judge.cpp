// @leet start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> trusted_by;
        unordered_map<int, int> trusts;

        for (const vector<int> &rel : trust) {
            trusts[rel[0]]++;
            trusted_by[rel[1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if ((trusted_by[i] == n - 1) && (trusts.find(i) == trusts.end())) {
                return i;
            }
        }
        return -1;
    }
};
// @leet end
