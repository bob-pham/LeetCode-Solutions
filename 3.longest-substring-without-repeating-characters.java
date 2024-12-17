// @leet start
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> charCount = new HashMap<>();
        char strChar[] = s.toCharArray();
        int result = 0;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            char curr = strChar[r];
            charCount.put(curr, charCount.getOrDefault(curr, 0) + 1);
            while (charCount.get(curr) > 1) {
                char left = strChar[l];
                charCount.put(left, charCount.getOrDefault(left, 0) - 1);
                l++;
            }
            result = Math.max(result, r - l + 1);
        }
        
        return result;
    }
}
// @leet end
