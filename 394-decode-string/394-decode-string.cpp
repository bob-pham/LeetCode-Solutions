class Solution {
public:
    string decodeString(string s) {
        
        stack<string> str_stck;
        stack<int> num_stck;
        string currStr = "";
        int num = 0;
        
        for (char c : s) {
            if (c == '[') {
                str_stck.push(currStr);
                num_stck.push(num);
                currStr = "";
                num = 0;
            } else if (c == ']') {
                string temp = str_stck.top();
                
                for (int i = num_stck.top(); i > 0; i--) {
                    temp += currStr;
                }
                
                currStr = temp;
                
                str_stck.pop();
                num_stck.pop();
            } else if (isdigit(c)) {
                num = num * 10 + int(c) - int('0') ;
            } else {
                currStr += c;
            }
        }
        
        return currStr;
    }
    };