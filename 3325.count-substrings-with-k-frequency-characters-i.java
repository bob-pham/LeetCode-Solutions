// @leet start
class Solution {
    public int numberOfSubstrings(String s, int k) {
        char charStr[] = s.toCharArray();
        int counts[] = {0};
        int charCount = 0;
        int l = 0;
        for (int r = 0; r < s.length(); r++) {
           int charIdx = r - 'a';
           counts[charStr[charIdx]]++;
           if (counts[charStr[charIdx]] - 1 < k) {
                charCount++;
           }

           while (charCount > 0) {
                int back = l - 'a';
                counts[charStr[back]]--;
                if (counts[charStr[back]] + 1 >= k) {
                    charCount++;
                }
           }
        }
    }
}
// @leet end
