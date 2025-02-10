// @leet start
class Solution {
public:
    string clearDigits(string s) {
        stack<char> char_stack;
        string result = "";

        for (char c : s) {
            if ('0' <= c && c <= '9' && !char_stack.empty()) {
                char_stack.pop();
            } else {
                char_stack.push(c);
            }
        }

        while (!char_stack.empty()) {
            result = char_stack.top() + result;
            char_stack.pop();
        }

        return result;
    }
};
// @leet end
