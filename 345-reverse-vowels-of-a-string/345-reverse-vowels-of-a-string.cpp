class Solution {
public:
    string reverseVowels(string s) {

        int left_ptr = 0;
        int length = s.length();
        int right_ptr = s.length() - 1;
        unordered_set<char> vowels;
        vowels.insert('a');
        vowels.insert('A');
        
        vowels.insert('e');
        vowels.insert('E');
        
        vowels.insert('i');
        vowels.insert('I');
        
        vowels.insert('o');
        vowels.insert('O');
        
        vowels.insert('u');
        vowels.insert('U');
        

        while (left_ptr < right_ptr && left_ptr < length && right_ptr >= 0) {

            while (left_ptr < length && vowels.find(s[left_ptr]) == vowels.end())
                left_ptr++;
            
            while (right_ptr >= 0 && vowels.find(s[right_ptr]) == vowels.end())
                right_ptr--;
            
            if (left_ptr >= right_ptr || left_ptr >= length || right_ptr < 0) {
                break;
            } 
            
            char temp = s[left_ptr];
            s[left_ptr] = s[right_ptr];
            s[right_ptr] = temp;
            left_ptr++;
            right_ptr--;
        }
        
        return s;
        
    }
};