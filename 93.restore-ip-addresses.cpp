// @leet start
#include <regex>
class Solution {
public:

    bool is_valid_ip(string s) {
        const std::regex pattern("(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})");

        if (!regex_match(s, pattern)) {
            return false;
        }

        std::vector<std::string> octets;
        std::regex chunk("(\\d{1,3})");
        auto begin = std::sregex_iterator(s.begin(), s.end(), chunk);
        auto end = std::sregex_iterator();

        for (auto it = begin; it != end; ++it) {
            octets.push_back(it->str());
        }

        // Output the result
        for (const auto& octet : octets) {
            int snum = stoi(octet);
            if (stoi(octet) > 255) {
                return false;
            }
            string s_str = to_string(snum);
            if (s_str != octet) {
                return false;
            }
        }

        return true;
    }

    void dfs(vector<string> &result, string s, int idx, int count) {
        if (count > 2) {
            if (is_valid_ip(s)) {
                result.push_back(s);
            }
            return;
        }

        int str_len = s.size();

        for (int i = 1; i < 4; i++) {
            string front = s.substr(0, min(idx + i, str_len));
            string end = s.substr(min(str_len, idx + i), str_len);
            string new_s = front + '.' + end;
            dfs(result, new_s, idx + i + 1, count + 1);
        }

    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;

        if (s.size() < 4) {
            return result;
        }

        dfs(result, s, 0, 0);

        return result;
    }
};
// @leet end
