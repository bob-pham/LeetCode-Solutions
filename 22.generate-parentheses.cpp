// @leet start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> found;
        vector<string> result;

        vectorHelper(n, "", result, found);
        return result;
    }

    bool isValid(string s) {
        stack<char> p;
        for (char c : s) {
            if (c == ')') {
                if (!p.empty() && p.top() == '(') {
                    p.pop();
                } else {
                    return false;
                }
            } else {
                p.push(c);
            }
        }

        return p.empty();
    }

    void vectorHelper(int n, string curr, vector<string> &result, unordered_set<string> &found) {
        if (curr.size() == n * 2) {
            result.push_back(curr);
            return;
        } else if (curr.size() > n * 2) {
            return;
        }
        string back = "()" + curr;
        string front = curr + "()";

        if (found.find(back) == found.end()) {
            found.insert(back);
            vectorHelper(n, back, result, found);
        }

        if (found.find(front) == found.end()) {
            found.insert(front);
            vectorHelper(n, front, result, found);
        }

        for (int i = 0; i < curr.size(); i++) {
            for (int j = i + 1; j < curr.size(); j++) {
                string next_string = curr.substr(0, i) + "(";

                next_string += curr.substr(i, j) + ")";
                next_string += curr.substr(j, curr.size());
                
                if (isValid(next_string) && (found.find(next_string) == found.end())) {
                    found.insert(next_string);
                    vectorHelper(n, next_string, result, found);
                }
            }
        }
    }

    
};
// @leet end
