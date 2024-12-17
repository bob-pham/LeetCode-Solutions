// @leet start
class Solution {
    public int minimumTimeToInitialState(String word, int k) {
        int seconds = 0;
        
        String baseStr = word.substring(k, word.length());
        char baseChars[] = baseStr.toCharArray();
        if (word.startsWith(baseStr)) {
            return true;
        }

        return seconds;
    }
}
// @leet end
