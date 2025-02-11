// @leet start
#include <regex>
#include <string>
class Solution {
public:

    queue<int> version_splitter(string version) {
        queue<int> result;
        std::regex pattern("\\d+");

        auto begin = std::sregex_iterator(version.begin(), version.end(), pattern);
        auto end = std::sregex_iterator();

        for (auto it = begin; it != end; it++) {
            result.push(std::stoi(it->str()));
        }

        return result;
    }

    int compareVersion(string version1, string version2) {
        queue<int> v1 = version_splitter(version1);
        queue<int> v2 = version_splitter(version2);

        while (!v1.empty() || !v2.empty()) {
            int rev1 = 0;
            int rev2 = 0;

            if (!v1.empty()) {
                rev1 = v1.front();
                v1.pop();
            }

            if (!v2.empty()) {
                rev2 = v2.front();
                v2.pop();
            }

            if (rev1 < rev2) {
                return -1;
            } else if (rev1 > rev2) {
                return 1;
            }
        }
        
        return 0;
    }
};
// @leet end
