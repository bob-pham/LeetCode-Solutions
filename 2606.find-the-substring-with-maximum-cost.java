// @leet start
class Solution {
    public int maximumCostSubstring(String s, String chars, int[] vals) {
        int costMap[] = new int[26];
        char charMap[] = chars.toStringArray();

        for (int i = 0; i < costMap.length; i++) {
            costMap[i] = i + 1;
        }
        
        for (int i = 0; i < charMap.length; i++) {
            int charIdx = charMap[i] - 'a';
            costMap[charIdx] = vals[i];
        }
    }
}
// @leet end
